/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RelationType.h
 * Author: marko
 *
 * Created on August 31, 2017, 8:17 PM
 */

#ifndef __RELATIONTYPE_H__
#define __RELATIONTYPE_H__
namespace core{
    namespace nfa{
        namespace state{
            enum RELATION_TYPE{
                NO_RELATION = 0,
                FRIEND,
                ENEMY
            };
        }
    }
}

#endif /* __RELATIONTYPE_H__ */

