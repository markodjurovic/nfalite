/* 
 * File:   RAIIS.h
 * Author: marko
 *
 * Created on June 1, 2014, 8:42 PM
 */

#ifndef RAIIS_H
#define	RAIIS_H

#include <pthread.h>
#include <fstream>


namespace core{
    namespace util{
        namespace raii{
                        
            class MutexRaii{
            private:
                pthread_mutex_t* mutex;
                MutexRaii(){
                    mutex = 0;
                }
            protected:
            public:
                MutexRaii(pthread_mutex_t* mtx){
                    mutex = mtx;
                    pthread_mutex_lock(mutex);
                }
                
                ~MutexRaii(){
                    if (mutex != 0)
                        pthread_mutex_unlock(mutex);
                }
            };
            
            class FileRaii{
            private:
                std::fstream* file;
                FileRaii(){}
            protected:
            public:
                FileRaii(std::fstream* file){
                    this->file = file;
                }
                
                ~FileRaii(){
                    if (file){
                        file->flush();
                        file->close();
                    }
                }
            };                                                
        }
    }
}

#endif	/* RAIIS_H */

