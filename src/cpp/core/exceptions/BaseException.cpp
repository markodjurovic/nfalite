#include "BaseException.h"
#include <iostream>

namespace core {
    namespace exceptions{
        
        BaseException::BaseException() : exception(){
            file = "";
            lineNum = -1;
            message = "";
        }
        
        void BaseException::init(std::string const fileName, int const lineNum){
            std::cout << "File: " << fileName << std::endl;
            this->file = fileName;
            std::cout << "File: " << file << std::endl;
            std::cout << "Line: " << lineNum << std::endl;
            this->lineNum = lineNum;
            std::cout << "Line: " << this->lineNum << std::endl;
        }
        
        BaseException::BaseException(std::string const fileName, int const lineNum) : exception(){
            init(fileName, lineNum);
        }
        
        BaseException::BaseException(std::string const fileName, int const lineNum, std::string const message) : exception(){
            init(fileName, lineNum);
            std::cout << "Message: " << message << std::endl;
            this->message = message;
            std::cout << "Message: " << this->message << std::endl;
        }

        BaseException::~BaseException(){
            int a =0;
            a++;
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
            std::cout << "File: " << file << std::endl;
            std::cout << "Line: " << this->lineNum << std::endl;
            std::cout << "Message: " << this->message << std::endl;
            std::string whatContainer = message + ", at: " + file + ", line: " + std::to_string(lineNum);
            return whatContainer.c_str();
        }
    }
}