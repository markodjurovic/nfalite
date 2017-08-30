#ifndef __TEST_RTTI_CLASS_HPP__
#define __TEST_RTTI_CLASS_HPP__

#include "core/util/rtti/ObjectFactory.h"

namespace test{
    class TestRTTIClass{
        PREPARE_REGISTRATION(TestRTTIClass);
    private:
    protected:
    public:
        int doSomething();
    };
}

#endif //__TEST_RTTI_CLASS_HPP__