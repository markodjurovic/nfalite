#ifndef __MACROS_H__
#define __MACROS_H__

#define PREPARE_REGISTRATION(CLASS_NAME) public:\
                                static void* __getClassInstanceSPC(){\
                                    return new CLASS_NAME();\
                                }    

#define REGISTER_CLASS(CLASS_NAME, NAMESPACE)   core::util::RTTI::RTTI* NAMESPACE ## _ ## CLASS_NAME ## _rtti = new core::util::RTTI::RTTI();\
                                                int NAMESPACE ## _ ## CLASS_NAME ## _a = NAMESPACE ## _ ## CLASS_NAME ## _rtti->setSingleton(false);\
                                                int NAMESPACE ## _ ## CLASS_NAME ## _b = NAMESPACE ## _ ## CLASS_NAME ## _rtti->setInstancer(&CLASS_NAME::__getClassInstanceSPC);\
                                                std::string NAMESPACE ## _ ## CLASS_NAME ## _clsIDISP = std::string(#NAMESPACE) + std::string("::") + std::string(#CLASS_NAME);\
                                                int NAMESPACE ## _ ## CLASS_NAME ## _c = core::util::RTTI::RTTIStorage::getInstancePtr()->registerClass(NAMESPACE ## _ ## CLASS_NAME ## _clsIDISP, NAMESPACE ## _ ## CLASS_NAME ## _rtti);

#define REGISTER_SINGLETON(CLASS_NAME, NAMESPACE)   core::util::RTTI::RTTI* NAMESPACE ## _ ## CLASS_NAME ## _rtti1 = new core::util::RTTI::RTTI();\
                                                    int NAMESPACE ## _ ## CLASS_NAME ## _a1 = NAMESPACE##_CLASS_NAME##_rtti1->setSingleton(true);\
                                                    int NAMESPACE ## _ ## CLASS_NAME ## _b1 = NAMESPACE##_CLASS_NAME##_rtti1->setInstancer(&CLASS_NAME::__getClassInstanceSPC);\
                                                    std::string NAMESPACE ## _ ## CLASS_NAME ## _clsIDISP1 = std::string(#NAMESPACE) + std::string("::") + std::string(#CLASS_NAME);\
                                                    int NAMESPACE ## _ ## CLASS_NAME ## _c = core::util::RTTI::RTTIStorage::getInstancePtr()->registerClass(NAMESPACE ## _ ## CLASS_NAME ## _clsIDISP1, NAMESPACE ## _ ## CLASS_NAME ## _rtti1);\
                                                    NAMESPACE::CLASS_NAME* NAMESPACE ## _ ## CLASS_NAME ## _singleton = NAMESPACE::CLASS_NAME::getInstancePtr();\
                                                    int d = core::util::RTTI::ObjectFactory::getInstancePtr()->registerSingleton(NAMESPACE ## _ ## CLASS_NAME ## _rtti1, NAMESPACE ## _ ## CLASS_NAME ## _singleton);

#endif //__MACROS_H__