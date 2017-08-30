/* 
 * File:   RAIIS.h
 * Author: marko
 *
 * Created on June 1, 2014, 8:42 PM
 */

#ifndef RAIIS_H
#define	RAIIS_H

#include <mutex>
#include <fstream>
#include <memory>

namespace core{
    namespace util{
        namespace raii{                                    
            
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

