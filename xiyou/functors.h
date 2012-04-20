/*
 * =====================================================================================
 *
 *       Filename:  functors.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 03:25:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _FUNCTORS_H_
#define _FUNCTORS_H_
#include"actor.h"
//用以累加actor功力值的函数对象类
class ActorPowersAccumulater
{
    public:
        int &_powers;
        ActorPowersAccumulater(int &powers)
            :_powers(powers)
        {
            //开始统计，初始化为0
            _powers = 0;
        }
        void operator()(Actor *actor)
        {
            _powers+=actor->getPower();
            _pwers += actor->getWeaponPowers();
        }
};
#endif
