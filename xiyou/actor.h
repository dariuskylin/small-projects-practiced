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

//��ɫ
class Game;
class Actor;
typedef vector< Actor * > Actors;
class Actor
{
    protected:
        string _name;//����
        bool _gender;//�Ա�
        int _power;//����
        Weapons _weapons;//��������б�
    public:
        //��������
        virtual ~Actor();
        Actor( string name, bool gender, int power);

        //���һ������
        virtual Actor& operator<(Weapon weapon);
        //ȡ���������ı���
        virtual Actor& operator>(Weapon& weapon);
        //��˵�Ի�
        virtual void say() const;
        void say( string message ) const;
        
        Actor& operator+=(int power);
        Actor& operator-=(int power);

        //ÿ�����ж�����
        virtual void onEveryDay( Game &game );
        //ս��ʱ�Ķ���
        virtual void onLose( Game &game,Actors &winners,Weapons &weapons);
        //սʤʱ�Ķ���
        virtual void onWin( Game &game,Actors &losers,Weapons &weapons);
        //������ʱ�Ķ���
        virtual void onKilled(Game &game,Actors &winners);

        //�������еı���
        Weapons& getWeapons(void) const;
        //��ȡ����
        string getName(void) const;
        //��ȡ����
        int getPower(void) const;
        //��ȡ�����������ܺ�
        int getWeaponPowers(void) const;
};
//������
ostream& operator<<(ostream& cout,Actor& actor);
//���ԱȽ�����Actor*
bool comparesActor(Actor* a1,Actor *a2);
#endif
