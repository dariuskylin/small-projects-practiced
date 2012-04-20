/*
 * =====================================================================================
 *
 *       Filename:  monk.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 10:11:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"monk.h"
Monk::Monk(string name,string monkName,int power)
    :Actor(name,true,power),_monkName(monkName)
{
    
}
Monk::~Monk()
{
    Actor::say("阿弥托佛，贫僧去也...");
}
void Monk::say()
{
    Actor::say("阿弥托佛，贫僧乃"+_monkName+"是也...");
}
void Monk::patter()
{
    cout<<_name<<":唵嘛呢叭咪吽..."<<endl;
}
string Monk::getName()
{
    return _name;
}
Actor & Monk::operator<<(Weapon & weapon)
{
    //和尚只能佩戴一样兵器
    if(_weapons.empty())
    {
        cout<<_name<<":兵器+"<<weapon<<endl;
        _weapons.push(weapon);
    }
    return *this;
}
//和尚只能佩戴一样兵器
void Monk::onWin(Game &game,Actors &losers,Weapons &weapons)
{
    //功力提高
    (*this)+=loser.size();
    //配上收缴的兵器
    if(!weapons.empty())
    {
        Weapon weapon = weapons.top();
        //还没兵器呢
        if(_weapons.empty())
        {
            (*this)<<weapon;
            weapons.pop();
        }
        //已经有一件了
        else
        {
            Weapon mine = _weapons.top();
            //如果缴获的兵器比自己的好，那就换了它
            if(mine<weapon)
            {
                //取出自己的
                (*this)>>mine;
                weapons.pop();
                weapons.push(mine);
                //转换新的兵器
                (*this)<<weapon;
            }
        }
    }
}
