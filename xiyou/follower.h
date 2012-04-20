/*
 * =====================================================================================
 *
 *       Filename:  follower.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 11:44:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _FOLLOWER_H_
#define _FOLLOWER_H_

#include"monster.h"
class FollowerMonster : public Monster
{
    private:
            string _newName;
            string _monkName;
    public:
            FollowerMonster(string name,int power,string place,string monkName);
            void onLose(Game &game,Actors &winners,Weapons &weapons);
            void onKilled(Game &game,Actors & winners);
};

#endif
