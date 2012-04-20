/*
 * =====================================================================================
 *
 *       Filename:  monster.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 09:59:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _MONSTER_H_
#define _MONSTER_H_

#include"actor.h"
class Monster : public Actor
{
    private:
            //住所
            string _place;
    public:
            Monster(string name,bool gender,int power,string place);
            //打招呼
            void say();
            //妖怪吃人
            void eat(Game &game,Actor * & food);
            void onEveryDay(Game &game);
};

#endif
