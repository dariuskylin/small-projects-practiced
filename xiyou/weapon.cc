/*
 * =====================================================================================
 *
 *       Filename:  weapon.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 01:21:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"weapon.h"

ostream& operator<<(ostream& cout, Weapon &weapon)
{
    cout<<weapon.getName()<<"("<<weapon.getPower()<<")";
    return cout;
}

Weapon::Weapon()
{
    
}

Weapon::Weapon( string name, int power)
    :_name(name),_power(power)
{
    
}

string Weapon::getName() const
{
    return _name;
}

int Weapon::getPower() const
{
    return _power;
}

bool operator<(Weapon &other) const
{
    return this->getPower()<other.getPower();    
}

bool operator>(Weapon &other) const
{
    return this->getPower()>other.getPower();
}

