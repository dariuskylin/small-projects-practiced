/*
 * =====================================================================================
 *
 *       Filename:  follower.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 11:47:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"follower.h"
#include"game.h"

FollowerMonster::FollowerMonster(string name,int power,string place,string newName,string monkName)
    :Monster(name,true,power,place),_newName(newName),_monkName(monkName)
{
    
}
void FollowerMonster::onKilled(Game &game,Actors &winners)
{
    //设置新的monk的属性
    //Game的createActor()函数从一个字符串流中读取属性
    stringstring ss;
    ss<<this->_newName<<endl<<this->_monkName<<endl<<this->power;

    //调用Game的createActor()函数创建一个monk
    Actor *actor = game.createActor("monk",ss);
    //将兵器转交过去
    while(!_weapons.empty())
    {
        (*actor)<<_weapons.top();
        _weapons.pop();
    }
    //跟随唐三藏，加入取经团队
    game.joinTravelers(actor);
    //销毁掉自己
    game.destroyActor(this);
}
void FollowerMonster::onLose(Game &game,Actors &winners,Weapons &weapons)
{
    //坚决不交出兵器!
}
