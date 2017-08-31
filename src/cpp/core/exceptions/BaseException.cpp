#include "BaseException.h"
#ifdef DEBUG
#include <iostream>
#endif

namespace core {
    namespace exceptions{
        
        BaseException::BaseException() : exception(){
            file = "";
            lineNum = -1;
            message = "";
        }
        
        void BaseException::init(std::string const fileName, int const lineNum){
#ifdef DEBUG
            std::cout << "File: " << fileName << std::endl;
            std::cout << "Line: " << lineNum << std::endl;
#endif
            this->file = fileName;                        
            this->lineNum = lineNum;            
        }
        
        BaseException::BaseException(std::string const fileName, int const lineNum) : exception(){
            init(fileName, lineNum);
        }
        
        BaseException::BaseException(std::string const fileName, int const lineNum, std::string const message) : exception(){
#ifdef DEBUG
            std::cout << "Message: " << message << std::endl;
#endif
            init(fileName, lineNum);            
            this->message = message;            
        }

        BaseException::~BaseException(){
#ifdef DEBUG
            std::cout << "Base exception destructor called" << std::endl;
#endif            
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
#ifdef DEBUG
            std::cout << "File: " << file << std::endl;
            std::cout << "Line: " << this->lineNum << std::endl;
            std::cout << "Message: " << this->message << std::endl;
#endif
            std::string whatContainer = message + ", at: " + file + ", line: " + std::to_string(lineNum);
            return whatContainer.c_str();
        }
    }
}