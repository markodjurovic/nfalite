#ifndef __STATE_MANAGER_H__
#define __STATE_MANAGER_H__

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include "core/util/Singleton.h"

namespace core{
    namespace nfa{
        namespace state{
            class BaseState;
            
            namespace manager{
                
                enum UNFRIEND_SAMEPRIORITY_STATE_POLICY{
                    EXECUTE_BOTH,
                    EXECUTE_ONE,                    
                    EXECUTE_NONE
                };
                
                class StateManager : public core::util::Singleton<StateManager>{
                    friend class core::util::Singleton<StateManager>;
                private:
                    StateManager();
                    virtual ~StateManager();
                    
                    UNFRIEND_SAMEPRIORITY_STATE_POLICY policyForSamePriorityUnfriendState;
                    
                    std::unordered_map<std::shared_ptr<void>, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>>> entitiesStates;
                    void updateEntity(std::shared_ptr<void> entity, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states);
                    std::vector<std::shared_ptr<core::nfa::state::BaseState>> getUnfriendlyStates(std::shared_ptr<core::nfa::state::BaseState>, std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> states);
                    void resetSkipUpdate();
                    void resetSkipUpdate(std::unordered_set<std::shared_ptr<core::nfa::state::BaseState>> &stateSet);
                protected:
                public:
                    void addTo(std::shared_ptr<void> entity, std::shared_ptr<core::nfa::state::BaseState> state);
                    void update();
                    void setSamePriorityUnfriendStatePolicy(UNFRIEND_SAMEPRIORITY_STATE_POLICY policy);
                    UNFRIEND_SAMEPRIORITY_STATE_POLICY getSamePriorityUnfriendStatePolicy();
                };
                
                
            }
        } 
    }
}

#endif //__STATE_MANAGER_H__