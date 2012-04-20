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
        string _name;//兵器名
        int _power;//威力
    public:
        Weapon();
        Weapon( string name, int power );

        string getName() const;
        int getPower() const;
        bool operator<(const Weapon &other) const;
        bool operator>(const Weapon &other) const;
};
typedef priority_queue< Weapon,vector< Weapon > >  Weapons;
//对流操作的支持
ostream& operator<<(ostream &cout,Weapon& weapon);
#endif
