/*
 * =====================================================================================
 *
 *       Filename:  functors.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 03:25:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _FUNCTORS_H_
#define _FUNCTORS_H_
#include"actor.h"
//�����ۼ�actor����ֵ�ĺ���������
class ActorPowersAccumulater
{
    public:
        int &_powers;
        ActorPowersAccumulater(int &powers)
            :_powers(powers)
        {
            //��ʼͳ�ƣ���ʼ��Ϊ0
            _powers = 0;
        }
        void operator()(Actor *actor)
        {
            _powers+=actor->getPower();
            _pwers += actor->getWeaponPowers();
        }
};
#endif
