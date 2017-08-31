#ifndef  __BASE_STATE_H__
#define __BASE_STATE_H__

#include <unordered_map>
#include "StateRelation.h"

namespace core{
    namespace nfa{
        namespace state{
            
            class BaseState{
            private:
                uint16_t priority;
                std::unordered_map<std::string, RELATION_TYPE> relations;
            protected:
            public:
                void addRelation(StateRelation relation);
                uint16_t getPriority() const;
                void setPriority(uint16_t priority);
                RELATION_TYPE getRelationWith();
            };
            
        }
    }
}

#endif