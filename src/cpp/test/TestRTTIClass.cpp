#include "TestRTTIClass.hpp"
#include "core/util/rtti/ObjectFactory.h"

namespace test{
    namespace inner{
        REGISTER_CLASS(TestRTTIClass, test::inner);

        int TestRTTIClass::doSomething(){
            return 1;
        }
    }
}
