#ifndef __TEST_RTTI_CLASS_HPP__
#define __TEST_RTTI_CLASS_HPP__

#include "core/util/rtti/macros.h"

namespace test{
    namespace inner{
        
        class TestRTTIClass{
            PREPARE_REGISTRATION(TestRTTIClass);
        private:
        protected:
        public:
            int doSomething();
        };
                
    }
}

#endif //__TEST_RTTI_CLASS_HPP__