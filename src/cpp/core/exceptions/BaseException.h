#ifndef __BASE_EXCEPTION_H__
#define __BASE_EXCEPTION_H__

#include <string>
#include <exception>
#include <math.h>

namespace core{
    namespace exceptions{
        
        class BaseException : public std::exception{
        private:            
        protected:
            std::string message;
            std::string file;
            int lineNum;
        public:
            BaseException(std::string const fileName, int const lineNum);
            BaseException(std::string const fileName, int const lineNum, std::string const message);
            virtual ~BaseException();
            virtual const char* what() const noexcept;
            
            std::string getFile() const;
            int getLineNum() const;
            std::string getMessage() const;

        };
        
    }
}


#endif