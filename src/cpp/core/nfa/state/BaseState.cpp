#include "BaseState.h"

namespace core{
    namespace nfa{
        namespace state{
            
            void BaseState::addRelation(StateRelation const relation){
                
            }
            
            unsigned BaseState::getPriority() const {
                return priority;
            }

            void BaseState::setPriority(unsigned priority) {
                this->priority = priority;
            }
            
        }
    }
}