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
    Actor::say("�����з�ƶɮȥҲ...");
}
void Monk::say()
{
    Actor::say("�����з�ƶɮ��"+_monkName+"��Ҳ...");
}
void Monk::patter()
{
    cout<<_name<<":�����ذ����..."<<endl;
}
string Monk::getName()
{
    return _name;
}
Actor & Monk::operator<<(Weapon & weapon)
{
    //����ֻ�����һ������
    if(_weapons.empty())
    {
        cout<<_name<<":����+"<<weapon<<endl;
        _weapons.push(weapon);
    }
    return *this;
}
//����ֻ�����һ������
void Monk::onWin(Game &game,Actors &losers,Weapons &weapons)
{
    //�������
    (*this)+=loser.size();
    //�����սɵı���
    if(!weapons.empty())
    {
        Weapon weapon = weapons.top();
        //��û������
        if(_weapons.empty())
        {
            (*this)<<weapon;
            weapons.pop();
        }
        //�Ѿ���һ����
        else
        {
            Weapon mine = _weapons.top();
            //����ɻ�ı������Լ��ĺã��Ǿͻ�����
            if(mine<weapon)
            {
                //ȡ���Լ���
                (*this)>>mine;
                weapons.pop();
                weapons.push(mine);
                //ת���µı���
                (*this)<<weapon;
            }
        }
    }
}
