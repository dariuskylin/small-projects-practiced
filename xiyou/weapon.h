/*
 * =====================================================================================
 *
 *       Filename:  weapon.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 01:14:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _WEAPON_H_
#define _WEAPON_H_
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Weapon
{
    private:
        string _name;//������
        int _power;//����
    public:
        Weapon();
        Weapon( string name, int power );

        string getName() const;
        int getPower() const;
        bool operator<(const Weapon &other) const;
        bool operator>(const Weapon &other) const;
};
typedef priority_queue< Weapon,vector< Weapon > >  Weapons;
//����������֧��
ostream& operator<<(ostream &cout,Weapon& weapon);
#endif
