/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TestState.h"
#include "core/util/rtti/ObjectFactory.h"

namespace test{
    REGISTER_CLASS(TestState, test);
    
    TestState::TestState() : core::nfa::state::BaseState(){
        
    }
    
    TestState::~TestState(){
        
    }
    
    void TestState::onEnter(){
        
    }
    
    void TestState::onUpdate(){
        
    }
    
    void TestState::onExit(){
        
    }
}