#ifndef  __BASE_STATE_H__
#define __BASE_STATE_H__

#include <unordered_map>
#include "StateRelation.h"

namespace core{
    namespace nfa{
        namespace state{
            
            class BaseState{
            private:
                unsigned int16_t priority;
                std::unordered_map<std::string, RELATION_TYPE> relations;
            protected:
            public:
                void addRelation(StateRelation relation);
                unsigned getPriority() const;
                void setPriority(unsigned priority);
                RELATION_TYPE getRelationWith()
            };
            
        }
    }
}

#endif