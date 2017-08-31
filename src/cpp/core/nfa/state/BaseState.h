#ifndef  __BASE_STATE_H__
#define __BASE_STATE_H__

#include <unordered_map>
#include "StateRelation.h"

namespace core{
    namespace nfa{
        namespace state{
            
            enum STATE_STATE{
                ENTER,
                UPDATE,
                EXIT
            };
            
            class BaseState{
            private:
                uint16_t priority;
                std::unordered_map<std::string, RELATION_TYPE> relations;                
            protected:
                STATE_STATE currentInnerState;
                virtual void onEnter() = 0;
                virtual void onUpdate() = 0;
                virtual void onExit() = 0;
            public:
                BaseState(); 
                void addRelation(StateRelation relation);
                uint16_t getPriority() const;
                void setPriority(uint16_t priority);
                RELATION_TYPE getRelationWith(std::string otherStateId);
                
                void update();
            };
            
        }
    }
}

#endif