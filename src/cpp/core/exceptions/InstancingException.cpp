/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "InstancingException.h"

using namespace std;

namespace core{
    namespace exceptions{

        InstancingException::InstancingException(std::string const fileName, int const lineNum) : BaseException(fileName, lineNum, "Create object instance exception") {
            
        }
        
        InstancingException::InstancingException(std::string const fileName, int const lineNum, std::string const message) : BaseException(fileName, lineNum, message){

        }

        InstancingException::~InstancingException(){
            
        }

    }
}
