/*
 * =====================================================================================
 *
 *       Filename:  actor.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 11:44:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<functional>
#include<algorithm>
#include"actor.h"
#include"game.h"

//比较a1和a2对兵器的需求大小
//角色的功力越大，其兵器的威力越小，则该角色对兵器的需求而越大
bool comparesActor(Actor *a1, Actor *a2)
{
    return (a1->getPower()-a1->getWeaponPowers())>
        (a2->getPower()-a2->getWeaponPowers());
}
Actor::~Actor()
{
    cout<<_name<<"至此隐退江湖..."<<endl;
}
Actor::Actor(string name,bool gender,int power)
    :_name(name),_gender(gender),_power(power)
{
    cout<<_name<<"出现..."<<endl;
}
void Actor::say() const
{
    cout<<_name<<": 我乃"<<_name<<"是也..."<<endl;
}
void Actor::say(string message) const
{
    cout<<_name<<" : "<<message<<endl;
}
//重载了<<，用以添加兵器
Actor& Actor::operator<<(Weapon weapon)
{
   cout<<_name<<" :兵器+"<<weapon<<endl;
   _weapons.push(weapon);
   return *this;
}
Actor& Actor::operator>>(Weapon &weapon)
{
    if(!_weapons.empty())
    {
        weapon = _weapons.top();
        cout<<_name<<":兵器-"<<weapon<<endl;
        _weapons.pop();
    }
    return *this;
}
//重载榴+=，用以增加功力
Actor& Actor::operator+=(int power)
{
    _power += power;
    return *this;
}
//重载了-=，用以减少功力
Actor& Actor::operator-=(int power)
{
    _power-=power;
    if(_power<0)
        _power= 0;
    return *this;
}
void Actor::onEveryDay(Game &game)
{
}
void Actor::onKilled(Game &game,Actors &winners)
{
    game.destroyActor(this);
}
void Actor::onLose(Game &game,Actors &winners,Weapons &weapons)
{
    (*this)-=winners.size();
    //交出兵器至weapons
    while(!_weapons.empty() && weapons.size() < winners.size())
    {
        Weapon weapon;
        (*this)>>weapon;

        weapons.push(weapon);
    }
}
void Actor::onWin(Game &game,Actor &losers,Weapons &weapons)
{
    //功力提高
    (*this)+=losers.size();
    //配上收缴的兵器
    if(!weapons.empty())
    {
        Weapon weapon=weapons.top();
        (*this)<<weapon;
        weapons.pop();
    }
}
Weapons& Actor::getWeapons(void) const
{
   return _weapons;
}
string Actor::getName(void) const
{
    return _name;
}
int Actor::getPower(void) const
{
    return _power;
}
int Actor::getWeaponPowers(void) const
{
    int powers = 0;
    Weapons weapons(_weapons);
    while(!weapons.empty())
    {
        Weapon weapon = weapons.top();
        powers += weapon.getPower();
        weapons.pop();
    }
    return powers;
}
ostream& operator<<(ostream& cout,Actor &actor)
{
    //输出姓名
    cout<<actor.getName()<<"("<<actor.getPower()<<")";
    //输出兵器
    //构造一个副本
    Weapons weapons(actor.getWeapons());
    if(!weapons.empty())
    {
        cout<<"[";
        while(!weapons.empty())
        {
            //取出顶部元素
            Weapon weapon= weapons.top();
            //输出兵器信息
            cout<<weapon;
            //弹出顶部的元素
            weapons.pop();
        }
        cout<<"]";
    }
    return cout;
}
