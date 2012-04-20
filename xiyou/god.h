/*
 * =====================================================================================
 *
 *       Filename:  god.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 10:21:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _GOD_H_
#define _GOD_H_

#include"actor.h"

/////////////////////////神仙//////////////////////////
class God : public Actor
{
    public:
        God(string name,bool gender,int power);

        void fly();//神仙可以飞来飞去
        void onWin(Game &game,Actor &losers,Weapons &weapons);
};

#endif
