#ifndef __STATE_RELATION_H__
#define __STATE_RELATION_H__

#include <string>

namespace core{
    namespace nfa{
        namespace state{
            
            enum RELATION_TYPE{
                NO_RELATION = 0,
                FRIEND,
                ENEMY
            };
            
            struct StateRelation{
                std::string stateClassId;
                RELATION_TYPE relation;
            };
        }
    }
}

#endif