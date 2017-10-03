#include "StateManager.h"
#include "core/nfa/state/BaseState.h"
#include <iterator>

namespace core{
    namespace nfa{
        namespace state{
            namespace manager{
                
                StateManager::StateManager(){
                    
                }
                
                StateManager::~StateManager(){
                    entitiesStates.clear();
                }
                
                void StateManager::addTo(std::shared_ptr<void> entity, std::shared_ptr<core::nfa::state::BaseState> state){
                    auto iter = entitiesStates.find(entity);
                    std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> stateSet;
                    if (iter == entitiesStates.end()){
                        stateSet = std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>();
                        entitiesStates[entity] = stateSet;                        
                    }
                    else{
                        stateSet = iter->second;
                    }
                    stateSet.insert(state);
                }                
                
                void StateManager::update(){
                    auto iter = entitiesStates.begin();
                    while (iter != entitiesStates.end()){
                        updateEntity(iter->first, iter->second);
                        iter++;
                    }
                    resetSkipUpdate();
                }
                
                void addToExcludedBy(std::unordered_map<std::shared_ptr<core::nfa::state::BaseState>, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>> &collection,
                                     std::shared_ptr<core::nfa::state::BaseState> excludedBy, std::shared_ptr<core::nfa::state::BaseState> excluded){
                    
                    auto iter = collection.find(excludedBy);
                    std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> excludedList;
                    if (iter == collection.end()){
                        collection[excludedBy] = excludedList;
                    }
                    else{
                        excludedList = iter->second;
                    }
                    excludedList.insert(excluded);
                }
                
                bool isInConflictWithSomeOtherThan(std::shared_ptr<core::nfa::state::BaseState> state, std::shared_ptr<core::nfa::state::BaseState> referentExclusionState, 
                                                   std::unordered_map<std::shared_ptr<core::nfa::state::BaseState>, 
                                                        std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>> &collection){
                    
                    //we will iterate through collection and check for all keys other than referentExclusionState
                    //if is that key in conflict with state
                    auto iter = collection.begin();
                    while (iter != collection.end()){
                        if (iter->first != referentExclusionState){
                            auto conflictSet = iter->second;
                            if (conflictSet.find(state) != conflictSet.end()){
                                return true;
                            }
                        }
                        iter++;
                    }
                    return false;
                }
                
                /**
                 * idea is to relax some states from skipping
                 * for example if state A cause that state B should be skipped,
                 * but state C cause that A should be skipped, and if no other state is in conflict with B
                 * then state B should be updated
                 * @param collection
                 */
                void relaxSkippingStates(std::unordered_map<std::shared_ptr<core::nfa::state::BaseState>, 
                                         std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>> &collection){
                    auto iter = collection.begin();
                    while (iter != collection.end()){
//                        auto causeOfConflict = iter->first;
                        auto conflicted = iter->second;
                        auto conflictedIter = conflicted.begin();
                        while (conflictedIter != conflicted.end()){
                            std::shared_ptr<core::nfa::state::BaseState> state = *conflictedIter;
                            //check if this state is cause of conflict for some other states
                            auto isStateCauseOfConflict = collection.find(state);
                            if (isStateCauseOfConflict != collection.end()){
                                //now we should check up if conflicted states should be relaxed
                                auto conflictedWithConflictedSet = isStateCauseOfConflict->second;
                                auto conflictdeWithConflictedIter = conflictedWithConflictedSet.begin();
                                while (conflictdeWithConflictedIter != conflictedWithConflictedSet.end()){
                                    auto conflictedOfConflicted = *conflictdeWithConflictedIter;
                                    if (!isInConflictWithSomeOtherThan(conflictedOfConflicted, state, collection)){
                                        //this means that conflictedOfConflicted is not in conflict with other states than state
                                        //so skip can be relaxed
                                        conflictedOfConflicted.get()->setSkipUpdate(false);                                        
                                    }
                                    conflictdeWithConflictedIter++;
                                }
                            }
                            conflictedIter++;
                        }
                        iter++;
                    }
                }
                
                std::unordered_map<std::shared_ptr<core::nfa::state::BaseState>, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>> StateManager::findStatesConflicts(std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states){
                    //track all states that will be skipped, and what state cause that skip
                    std::unordered_map<std::shared_ptr<core::nfa::state::BaseState>, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>> conflicts;
                    
                    auto iter = states.begin();
                    
                    while (iter != states.end()){
                        std::shared_ptr<core::nfa::state::BaseState> statePtr = *iter;
                        std::vector<std::shared_ptr<core::nfa::state::BaseState>> unfriendlyStates = getUnfriendlyStates(statePtr, states);
                        auto statePriority = statePtr.get()->getPriority();                        
                        for (int i = 0; i < unfriendlyStates.size(); i++){
                            std::shared_ptr<core::nfa::state::BaseState> unfriendlyState = unfriendlyStates[i];
                            auto unfriendlyStatePriority = unfriendlyState.get()->getPriority(); 
                            if (unfriendlyStatePriority > statePriority){                                
                                addToExcludedBy(conflicts, unfriendlyState, statePtr);
                                statePtr.get()->setSkipUpdate(true);
                            }
                            if (unfriendlyStatePriority == statePriority){
                                switch (policyForSamePriorityUnfriendState){
                                    case EXECUTE_NONE:
                                        statePtr.get()->setSkipUpdate(true);
                                        addToExcludedBy(conflicts, unfriendlyState, statePtr);
                                        unfriendlyState.get()->setSkipUpdate(true);
                                        addToExcludedBy(conflicts, statePtr, unfriendlyState);
                                        break;
                                    case EXECUTE_ONE:
                                        unfriendlyState.get()->setSkipUpdate(true);
                                        addToExcludedBy(conflicts, statePtr, unfriendlyState);
                                        break;
                                }                                
                            }
                        }
                        iter++;
                    }
                    
                    return conflicts;
                }
                
                void StateManager::updateEntity(std::shared_ptr<void> entity, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states){                                                            
                    
                    auto conflicts = findStatesConflicts(states);
                                        
                    relaxSkippingStates(conflicts);
                    
                    //update states
                    auto iter = states.begin();
                    while (iter != states.end()){
                        std::shared_ptr<core::nfa::state::BaseState> statePtr = *iter;
                        statePtr.get()->update();                        
                        iter++;
                    }
                }
                
                std::vector<std::shared_ptr<core::nfa::state::BaseState>> StateManager::getUnfriendlyStates(std::shared_ptr<core::nfa::state::BaseState> state, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states){
                    //TODO get all directly and indirectly unfriendly states
                }
                
                void StateManager::setSamePriorityUnfriendStatePolicy(UNFRIEND_SAMEPRIORITY_STATE_POLICY policy){
                    policyForSamePriorityUnfriendState = policy;
                }
                
                UNFRIEND_SAMEPRIORITY_STATE_POLICY StateManager::getSamePriorityUnfriendStatePolicy(){
                    return policyForSamePriorityUnfriendState;                    
                }
                
                void StateManager::resetSkipUpdate(){
                    auto iter = entitiesStates.begin();
                    while (iter != entitiesStates.end()){
                        std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> entityStatesSet = iter->second;
                        resetSkipUpdate(entityStatesSet);
                        iter++;
                    }
                }
                
                void StateManager::resetSkipUpdate(std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> &stateSet){
                    auto setIter = stateSet.begin();
                    while (setIter != stateSet.end()){
                        (*setIter).get()->setSkipUpdate(false);
                        setIter++;
                    }
                }
            }
        } 
    }
}