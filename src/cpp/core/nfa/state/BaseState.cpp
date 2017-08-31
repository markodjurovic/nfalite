#include "BaseState.h"

namespace core{
    namespace nfa{
        namespace state{
            
            void BaseState::addRelation(StateRelation const relation){
                
            }
            
            uint16_t BaseState::getPriority() const {
                return priority;
            }

            void BaseState::setPriority(uint16_t priority) {
                this->priority = priority;
            }
            
            RELATION_TYPE BaseState::getRelationWith(std::string otherStateId){
                return NO_RELATION;
            }
            
        }
    }
}