/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InstancingException.h
 * Author: marko
 *
 * Created on August 30, 2017, 2:24 PM
 */

#ifndef __INSTANCING_EXCEPTION_H__
#define __INSTANCING_EXCEPTION_H__

#include "BaseException.h"

namespace core{
    namespace exceptions{
        
        class InstancingException : public BaseException{
        private:
        protected:
        public:
            InstancingException(std::string const fileName, int const lineNum);
            InstancingException(std::string const fileName, int const lineNum, std::string const message);
            virtual ~InstancingException();
        };
        
    }
}


#define THROW_INSTANCING_EXCEPTION_WITH_MESSAGE(MESSAGE) throw core::exceptions::InstancingException(__FILE__, __LINE__, MESSAGE)
#define THROW_INSTANCING_EXCEPTION() throw core::exceptions::InstancingException(__FILE__, __LINE__)

#endif /* __INSTANCING_EXCEPTION_H__ */

