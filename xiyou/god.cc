/*
 * =====================================================================================
 *
 *       Filename:  god.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 01:05:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"god.h"
God::God(string name,bool gender,int power)
    :Actor(name,gender,power)
{

}
void God::fly()
{
    say("飞呀飞...");
}
void God::onWin(Game &game,Actor &losers,Weapons &weapons)
{
    //功力提高
    (*this) += losers.size();
    //神仙不需要和取经人抢兵器
}
