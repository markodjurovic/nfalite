#ifndef __MACROS_H__
#define __MACROS_H__

#define PREPARE_REGISTRATION(CLASS_NAME) public:\
                                static void* __getClassInstanceSPC(){\
                                    return new CLASS_NAME();\
                                }    

#define REGISTER_CLASS(CLASS_NAME, NAMESPACE)   core::util::RTTI::RTTI* CLASS_NAME ## _rtti = new core::util::RTTI::RTTI();\
                                                int CLASS_NAME ## _a = CLASS_NAME ## _rtti->setSingleton(false);\
                                                int CLASS_NAME ## _b = CLASS_NAME ## _rtti->setInstancer(&CLASS_NAME::__getClassInstanceSPC);\
                                                std::string CLASS_NAME ## _clsIDISP = std::string(#NAMESPACE) + std::string("::") + std::string(#CLASS_NAME);\
                                                int CLASS_NAME ## _c = core::util::RTTI::RTTIStorage::getInstancePtr()->registerClass(CLASS_NAME ## _clsIDISP, CLASS_NAME ## _rtti);

#define REGISTER_SINGLETON(CLASS_NAME, NAMESPACE)   core::util::RTTI::RTTI* CLASS_NAME ## _rtti1 = new core::util::RTTI::RTTI();\
                                                    int CLASS_NAME ## _a1 = CLASS_NAME ## _rtti1->setSingleton(true);\
                                                    int CLASS_NAME ## _b1 = CLASS_NAME ## _rtti1->setInstancer(&CLASS_NAME::__getClassInstanceSPC);\
                                                    std::string CLASS_NAME ## _clsIDISP1 = std::string(#NAMESPACE) + std::string("::") + std::string(#CLASS_NAME);\
                                                    int CLASS_NAME ## _c = core::util::RTTI::RTTIStorage::getInstancePtr()->registerClass(CLASS_NAME ## _clsIDISP1, CLASS_NAME ## _rtti1);\
                                                    NAMESPACE::CLASS_NAME* CLASS_NAME ## _singleton = NAMESPACE::CLASS_NAME::getInstancePtr();\
                                                    int d = core::util::RTTI::ObjectFactory::getInstancePtr()->registerSingleton(CLASS_NAME ## _rtti1, CLASS_NAME ## _singleton);

#endif //__MACROS_H__