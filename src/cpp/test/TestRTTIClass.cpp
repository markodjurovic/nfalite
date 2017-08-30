#include "TestRTTIClass.hpp"

namespace test{
    REGISTER_CLASS(TestRTTIClass, test);
    
    int TestRTTIClass::doSomething(){
        return 1;
    }
}
