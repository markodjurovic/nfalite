/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marko
 *
 * Created on August 27, 2017, 1:36 PM
 */

#include <cstdlib>
#include "core/util/rtti/ObjectFactory.h"
#include "test/DummyClass.hpp"
#include "test/TestRTTIClass.hpp"
#include <iostream>
#include <memory>
#include "test/TestState.h"

using namespace std;

/*
 * 
 */



void testRTTIFail(){
    auto objectFactory = core::util::RTTI::ObjectFactory::getInstancePtr();
    try{
        std::string classId("dummyClassID");
        DummyClass* tstObj = objectFactory->createInstance<DummyClass>(classId);
        delete tstObj;
        std::cout << "SUCCESS" << std::endl;
    }
    catch (core::exceptions::BaseException &exc){
        std::cout << exc.what() << std::endl;
    }
}

void testRTTIWork(){
    try{        
        std::shared_ptr<test::inner::TestRTTIClass> tstObjPtr(GET_OBJECT_INSTANCE(TestRTTIClass, test::inner));
        std::cout << tstObjPtr.get()->doSomething() << std::endl;
        std::cout << "SUCCESS" << std::endl;
    }
    catch (core::exceptions::BaseException &exc){
        std::cout << exc.what() << std::endl;
    }
}

void testStateOperator(){    
    try{
        std::string classId("test::TestState");
        std::shared_ptr<test::TestState> tstObjPtr1(GET_OBJECT_INSTANCE(TestState, test));
        tstObjPtr1.get()->setPriority(12);
        test::TestState testObj2 = *(tstObjPtr1.get());
        std::cout << testObj2.getPriority() << std::endl;
    }
    catch (core::exceptions::BaseException &exc){
        std::cout << exc.what() << std::endl;
    }
}

int main(int argc, char** argv) {
    testRTTIFail();
    testRTTIWork();
    testStateOperator();
    return 0;
}

