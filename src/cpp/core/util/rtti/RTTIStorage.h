#ifndef __RTTI_STORAGE_H__
#define __RTTI_STORAGE_H__

#include <unordered_map>
#include "core/util/Singleton.h"

namespace core{
    namespace util{
        namespace RTTI{
            
            class RTTIStorage : public core::util::Singleton<RTTIStorage>{
                friend class core::util::Singleton<RTTIStorage>;
            private:
                std::mutex mutex;
                std::unordered_map<std::string const, RTTI*> mappedRTTIs;
            protected:
                RTTIStorage() : core::util::Singleton<RTTIStorage>(){                    
                }
            public:
                virtual ~RTTIStorage(){}
                
                int registerClass(std::string const &classID, RTTI* rtti){                
                    std::lock_guard<std::mutex> lock(mutex);
                    mappedRTTIs[classID] = rtti;
                    return 1;
                }
                
                RTTI* getClassRTTI(std::string const &classID){
                    std::lock_guard<std::mutex> lock(mutex);
                    std::unordered_map<std::string, RTTI*>::iterator iter = mappedRTTIs.find(classID);
                    if (iter == mappedRTTIs.end())
                        return 0;
                    return iter->second;
                }
            };
            
        }
    }
}

#endif
