/* 
 * File:   Singleton.h
 * Author: marko
 *
 * Created on May 31, 2014, 6:34 PM
 */

#ifndef SINGLETON_H
#define	SINGLETON_H

#include "typedefs.h"
#include <mutex>
#include <memory>

namespace core{
    namespace util{
        
        /**
         * template singleton class
         */
        template <class T> class Singleton{
        private:
            static T* instancePtr;            
        protected:
            Singleton();            
            virtual ~Singleton();
        public:
            /**
             * 
             * @return instance of T class
             */
            static T* getInstancePtr();
            /**
             * maybe someone will call it sometime !!??
             */
            static void destroy();
        };
        
        template<class T> T* Singleton<T>::instancePtr = 0;
        
        template<class T> Singleton<T>::Singleton(){            
        }
        
        template<class T> Singleton<T>::~Singleton(){            
        }
        
        template<class T> T* Singleton<T>::getInstancePtr(){            
            std::mutex mutex;
            std::lock_guard<std::mutex> autoLock(mutex);
            static T* instancePtrTmp = 0;
            if (instancePtrTmp == 0 || instancePtr == 0){
                instancePtrTmp = new T();
                if (instancePtrTmp == 0){
                    //TODO
                }
                else{
                    instancePtr = instancePtrTmp;
                }
            }
            return instancePtr;
        }
        
        template<class T> void Singleton<T>::destroy(){           
            std::mutex mutex;
            std::lock_guard<std::mutex> autoLock(mutex);
            if (instancePtr != 0){
                delete(instancePtr);
            }
            instancePtr = 0;
        }

    }
}

#endif	/* SINGLETON_H */

