#include "BaseState.h"
#include "StateRelation.h"

namespace core{
    namespace nfa{
        namespace state{
            
            BaseState::BaseState(){
                currentInnerState = ENTER;
            }
            
            BaseState& BaseState::operator=(BaseState const &other){
                this->currentInnerState = other.currentInnerState;
                this->priority = other.priority;
                this->relations = other.relations;
            }
            
            void BaseState::addRelation(StateRelation const &relation){
                
            }
            
            uint16_t BaseState::getPriority() const {
                return priority;
            }

            void BaseState::setPriority(uint16_t const priority) {
                this->priority = priority;
            }
            
            RELATION_TYPE BaseState::getRelationWith(std::string const &otherStateId){
                std::unordered_map<std::string, RELATION_TYPE>::const_iterator iter = relations.find(otherStateId);
                if (iter == relations.end()){
                    return NO_RELATION;
                }
                return iter->second;
            }
            
            void BaseState::update(){
                switch (currentInnerState){
                    case ENTER:
                        onEnter();
                        currentInnerState = UPDATE;
                        break;
                    case UPDATE:
                        onUpdate();
                        break;
                    case EXIT:
                        onExit();
                        break;
                }
            }
            
            void BaseState::setCurrentEntity(std::shared_ptr<void> const entity){
                currentEntity = entity;
            }
        }
    }
}