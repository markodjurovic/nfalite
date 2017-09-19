#ifndef  __BASE_STATE_H__
#define __BASE_STATE_H__

#include <unordered_map>
#include "RelationType.h"
#include "InnerState.h"
#include <memory>

namespace core{
    namespace nfa{
        namespace state{
            
            struct StateRelation;
                        
            class BaseState{
            private:
                uint16_t priority;
                std::unordered_map<std::string, RELATION_TYPE> relations;
                bool skipUpdate;
            protected:
                STATE_STATE currentInnerState;
                std::shared_ptr<void> currentEntity;
                
                virtual void onEnter() = 0;
                virtual void onUpdate() = 0;
                virtual void onExit() = 0;
            public:
                BaseState(); 
                void addRelation(StateRelation const &relation);
                uint16_t getPriority() const;
                void setPriority(uint16_t const priority);
                RELATION_TYPE getRelationWith(std::string const &otherStateId);
                void update();
                
                void setCurrentEntity(std::shared_ptr<void> const entity);
                void setSkipUpdate(bool value);
                
                BaseState& operator=(BaseState const &other);
            };
            
        }
    }
}

#endif