/*
 * =====================================================================================
 *
 *       Filename:  actor.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 01:31:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _ACTOR_H_
#define _ACTOR_H_
#include<iostream>
#include<string>
#include<vector>
#include"weapon.h"

using namespace std;

//角色
class Game;
class Actor;
typedef vector< Actor * > Actors;
class Actor
{
    protected:
        string _name;//姓名
        bool _gender;//性别
        int _power;//功力
        Weapons _weapons;//佩戴兵器列表
    public:
        //析构函数
        virtual ~Actor();
        Actor( string name, bool gender, int power);

        //添加一件兵器
        virtual Actor& operator<(Weapon weapon);
        //取出威力最大的兵器
        virtual Actor& operator>(Weapon& weapon);
        //自说自话
        virtual void say() const;
        void say( string message ) const;
        
        Actor& operator+=(int power);
        Actor& operator-=(int power);

        //每天例行东操作
        virtual void onEveryDay( Game &game );
        //战败时的动作
        virtual void onLose( Game &game,Actors &winners,Weapons &weapons);
        //战胜时的动作
        virtual void onWin( Game &game,Actors &losers,Weapons &weapons);
        //被消灭时的动作
        virtual void onKilled(Game &game,Actors &winners);

        //返回所有的兵器
        Weapons& getWeapons(void) const;
        //获取名字
        string getName(void) const;
        //获取威力
        int getPower(void) const;
        //获取武器的威力总和
        int getWeaponPowers(void) const;
};
//流操作
ostream& operator<<(ostream& cout,Actor& actor);
//用以比较两个Actor*
bool comparesActor(Actor* a1,Actor *a2);
#endif
