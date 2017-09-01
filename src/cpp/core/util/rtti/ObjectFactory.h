#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__

#include "RTTI.h"
#include "RTTIStorage.h"
#include "../../exceptions/InstancingException.h"

namespace core{        
    
    namespace util{
                
        namespace RTTI{
            
            class ObjectFactory : public Singleton<ObjectFactory>{
                friend class Singleton<ObjectFactory>;
            private:
                ObjectFactory(){                    
                }
                
                std::mutex mutex;
                std::unordered_map<std::string, void*> mappedSingletons;
                void* getSingleton(std::string classID);
            protected:
            public:
                virtual ~ObjectFactory(){}
                
                template<class T> T* createInstance(std::string const classID){
                    core::util::RTTI::RTTI* rtti = RTTIStorage::getInstancePtr()->getClassRTTI(classID);
                    if (rtti == 0){
                        THROW_INSTANCING_EXCEPTION_WITH_MESSAGE("Can't find appropriate RTTI object, is class: " + classID + " registered to RTTI?");
                    }
                                        
                    if (rtti->isSingleton() == false){
                        T* instance = static_cast<T*>(rtti->getClassInstance());
                        if (instance == 0){
                            THROW_INSTANCING_EXCEPTION_WITH_MESSAGE("Can't instance class: " + classID);
                        }
                        return instance;
                    }
                    else{
                        void* tmpInstance = getSingleton(classID);
                        if (tmpInstance == 0){
                            THROW_INSTANCING_EXCEPTION_WITH_MESSAGE("Can't instance singleton class: " + classID);
                        }                        
                        T* instance = static_cast<T*>(tmpInstance);
                        return instance;
                    }
                }
                                
                int registerSingleton(std::string classID, void* singleton);
            };
            
        }
    }
}

#define GET_OBJECT_INSTANCE(CLASS_NAME, NAMESPACE) core::util::RTTI::ObjectFactory::getInstancePtr()->createInstance<NAMESPACE::CLASS_NAME>(std::string(#NAMESPACE) + std::string("::") + std::string(#CLASS_NAME))

#endif 
