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
    //���˳�ɽ��������Ҳ...
    Actor::say("����"+_place+name+"��Ҳ...");
}
void Monster::eat(Game &game,Actor * & food)
{
    cout<<_name<<"�Ե�"<<food->getName()<<"..."<<endl;
    //���ٵ�actor����
    game.destroyActor(food);
    food = 0;
}
void Monster::onEveryDay(Game &game)
{
    (*this)+=2;
}
