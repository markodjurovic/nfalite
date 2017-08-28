#include "ObjectFactory.h"

namespace core {
    namespace util {
        namespace RTTI {

            using namespace core::tools::image;
            using namespace core::util::prediction;
            using namespace std;
            using namespace core::util;
            
            void* ObjectFactory::getSingleton(std::string classID){
                raii::MutexRaii autoLock(&mutex);
                std::unordered_map<std::string, void*>::iterator iter = mappedSingletons.find(classID);
                if (iter != mappedSingletons.end())
                    return iter->second;
                return 0;
            }                        
            
            int ObjectFactory::registerSingleton(std::string classID, void* singleton){
                raii::MutexRaii autoLock(&mutex);
                mappedSingletons[classID] = singleton;
                return 1;
            }
        }
    }
}
