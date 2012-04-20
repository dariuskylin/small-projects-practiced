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

//�Ƚ�a1��a2�Ա����������С
//��ɫ�Ĺ���Խ�������������ԽС����ý�ɫ�Ա����������Խ��
bool comparesActor(Actor *a1, Actor *a2)
{
    return (a1->getPower()-a1->getWeaponPowers())>
        (a2->getPower()-a2->getWeaponPowers());
}
Actor::~Actor()
{
    cout<<_name<<"�������˽���..."<<endl;
}
Actor::Actor(string name,bool gender,int power)
    :_name(name),_gender(gender),_power(power)
{
    cout<<_name<<"����..."<<endl;
}
void Actor::say() const
{
    cout<<_name<<": ����"<<_name<<"��Ҳ..."<<endl;
}
void Actor::say(string message) const
{
    cout<<_name<<" : "<<message<<endl;
}
//������<<��������ӱ���
Actor& Actor::operator<<(Weapon weapon)
{
   cout<<_name<<" :����+"<<weapon<<endl;
   _weapons.push(weapon);
   return *this;
}
Actor& Actor::operator>>(Weapon &weapon)
{
    if(!_weapons.empty())
    {
        weapon = _weapons.top();
        cout<<_name<<":����-"<<weapon<<endl;
        _weapons.pop();
    }
    return *this;
}
//������+=���������ӹ���
Actor& Actor::operator+=(int power)
{
    _power += power;
    return *this;
}
//������-=�����Լ��ٹ���
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
    //����������weapons
    while(!_weapons.empty() && weapons.size() < winners.size())
    {
        Weapon weapon;
        (*this)>>weapon;

        weapons.push(weapon);
    }
}
void Actor::onWin(Game &game,Actor &losers,Weapons &weapons)
{
    //�������
    (*this)+=losers.size();
    //�����սɵı���
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
    //�������
    cout<<actor.getName()<<"("<<actor.getPower()<<")";
    //�������
    //����һ������
    Weapons weapons(actor.getWeapons());
    if(!weapons.empty())
    {
        cout<<"[";
        while(!weapons.empty())
        {
            //ȡ������Ԫ��
            Weapon weapon= weapons.top();
            //���������Ϣ
            cout<<weapon;
            //����������Ԫ��
            weapons.pop();
        }
        cout<<"]";
    }
    return cout;
}
