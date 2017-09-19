#include "BaseState.h"
#include "StateRelation.h"
#include "core/nfa/state/manager/StateManager.h"
#include <memory>

namespace core{
    namespace nfa{
        namespace state{
            
            BaseState::BaseState(){
                currentInnerState = ENTER;
                skipUpdate = false;
            }
            
            BaseState& BaseState::operator=(BaseState const &other){
                this->currentInnerState = other.currentInnerState;
                this->priority = other.priority;
                this->relations = other.relations;
                //this->currentEntity = other.currentEntity;
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
                auto iter = relations.find(otherStateId);
                if (iter == relations.end()){
                    return NO_RELATION;
                }
                return iter->second;
            }
            
            void BaseState::update(){
                if (skipUpdate){
                    skipUpdate = false;
                    return;
                }
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
                manager::StateManager::getInstancePtr()->addTo(entity, std::shared_ptr<BaseState>(this));
            }
            
            void BaseState::setSkipUpdate(bool value){
                skipUpdate = value;
            }
        }
    }
}