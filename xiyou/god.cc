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
    say("��ѽ��...");
}
void God::onWin(Game &game,Actor &losers,Weapons &weapons)
{
    //�������
    (*this) += losers.size();
    //���ɲ���Ҫ��ȡ����������
}
