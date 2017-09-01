#ifndef __STATE_RELATION_H__
#define __STATE_RELATION_H__

#include <string>

namespace core{
    namespace nfa{
        namespace state{
            struct StateRelation{
                std::string stateClassId;
                RELATION_TYPE relation;
            };
        }
    }
}

#endif