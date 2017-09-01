/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestState.h
 * Author: marko
 *
 * Created on August 31, 2017, 8:30 PM
 */

#include "core/nfa/state/BaseState.h"
#include "core/util/rtti/macros.h"

#ifndef __TESTSTATE_H__
#define __TESTSTATE_H__

namespace test{
    class TestState : public core::nfa::state::BaseState{
        PREPARE_REGISTRATION(TestState);
    private:        
    protected:
        virtual void onEnter() override;
        virtual void onUpdate() override;
        virtual void onExit() override;
    public:
        TestState();
        virtual ~TestState();
    };
}

#endif /* __TESTSTATE_H__ */

