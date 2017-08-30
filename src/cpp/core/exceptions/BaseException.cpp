#include "BaseException.h"


namespace core {
    namespace exceptions{
        
        BaseException::BaseException(std::string const fileName, int const lineNum){
            this->file = fileName;
            this->lineNum = lineNum;
        }
        
        BaseException::BaseException(std::string const fileName, int const lineNum, std::string const message) {
            BaseException(fileName, lineNum);
            this->message = message;
        }

        BaseException::~BaseException(){
            
        }
        
        std::string BaseException::getFile() const {
            return file;
        }

        int BaseException::getLineNum() const {
            return lineNum;
        }

        std::string BaseException::getMessage() const {
            return message;
        }
        
        const char* BaseException::what() const noexcept{
            return message.c_str();
        }
    }
}