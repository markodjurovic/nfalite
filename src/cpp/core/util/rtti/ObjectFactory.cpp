#include "ObjectFactory.h"

namespace core {
    namespace util {
        namespace RTTI {
            
            using namespace std;
            using namespace core::util;
            
            void* ObjectFactory::getSingleton(std::string classID){
                std::lock_guard<std::mutex> autoLock(mutex);
                std::unordered_map<std::string, void*>::iterator iter = mappedSingletons.find(classID);
                if (iter != mappedSingletons.end())
                    return iter->second;
                return 0;
            }                        
            
            int ObjectFactory::registerSingleton(std::string classID, void* singleton){
                std::lock_guard<std::mutex> autoLock(mutex);
                mappedSingletons[classID] = singleton;
                return 1;
            }
        }
    }
}
