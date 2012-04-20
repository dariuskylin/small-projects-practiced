/*
 * =====================================================================================
 *
 *       Filename:  monster.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 10:02:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"game.h"
#include"monster.h"

Monster::Monster(string name,bool gender,int power,string place)
    :Actor(name,gender,power),_place(place)
{
    
}
void Monster::say()
{
    //我乃常山赵子龙是也...
    Actor::say("我乃"+_place+name+"是也...");
}
void Monster::eat(Game &game,Actor * & food)
{
    cout<<_name<<"吃掉"<<food->getName()<<"..."<<endl;
    //销毁掉actor对象
    game.destroyActor(food);
    food = 0;
}
void Monster::onEveryDay(Game &game)
{
    (*this)+=2;
}
