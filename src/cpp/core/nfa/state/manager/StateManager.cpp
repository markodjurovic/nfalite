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
                
                void StateManager::updateEntity(std::shared_ptr<void> entity, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states){
                    auto iter = states.begin();
                    while (iter != states.end()){
                        std::shared_ptr<core::nfa::state::BaseState> statePtr = *iter;
                        std::vector<std::shared_ptr<core::nfa::state::BaseState>> unfriendlyStates = getUnfriendlyStates(statePtr, states);
                        auto statePriority = statePtr.get()->getPriority();                        
                        for (int i = 0; i < unfriendlyStates.size(); i++){
                            std::shared_ptr<core::nfa::state::BaseState> unfriendlyState = unfriendlyStates[i];
                            auto unfriendlyStatePriority = unfriendlyState.get()->getPriority(); 
                            if (unfriendlyStatePriority > statePriority){
                                //TODO relax all which will be skipped because of this one
                                //need some kind of tree
                                statePtr.get()->setSkipUpdate(true);                                
                                break;
                            }
                            if (unfriendlyStatePriority == statePriority){
                                switch (policyForSamePriorityUnfriendState){
                                    case EXECUTE_NONE:
                                        statePtr.get()->setSkipUpdate(true);
                                        unfriendlyState.get()->setSkipUpdate(true);
                                        break;
                                    case EXECUTE_ONE:
                                        unfriendlyState.get()->setSkipUpdate(true);
                                        break;
                                }                                
                            }
                        }                        
                        statePtr.get()->update();                        
                        iter++;
                    }
                }
                
                std::vector<std::shared_ptr<core::nfa::state::BaseState>> StateManager::getUnfriendlyStates(std::shared_ptr<core::nfa::state::BaseState>, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states){
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