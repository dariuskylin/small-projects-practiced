/*
 * =====================================================================================
 *
 *       Filename:  monk.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 10:08:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _MONK_H_
#define _MONK_H_
#include"actor.h"
class Monk :public Actor
{
    private:
            string _monkName;
    public:
            string getName();
            Monk(string name,string monkName,int power);
            ~Monk();
            void say();//´òÕÐºô
            void patter();//Äî¾­
            Actor& operator<<(Weapon &weapon);
            void onWin(Game &game,Actors &losers,Weapons &weapons);
};
#endif
