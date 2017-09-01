#include "TestRTTIClass.hpp"
#include "core/util/rtti/ObjectFactory.h"

namespace test{
    REGISTER_CLASS(TestRTTIClass, test);
    
    int TestRTTIClass::doSomething(){
        return 1;
    }
}
