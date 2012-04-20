/*
 * =====================================================================================
 *
 *       Filename:  game.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 12:06:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _GAME_H_
#define _GAME_H_

#include"actor.h"
#include"monk.h"
#include"god.h"
#include"follower.h"

#include<fstream>
#include<sstream>
#include<vector>
#include<list>
#include<map>

using namespace std;

/////////////////�ⲿ����///////////////////////
string replace(string &src,string find,string replacement);
/////////////////Game///////////////////////////
class Game
{
    private:
            //�ڼ���
            int _level;
            //��Ϸ��������������
            int _days;
            //���н�ɫ
            map<string,Actor *> _actors;
            //ȡ���Ŷ�
            Actors _travelers;
            //�����ػᱻ�����õ������Խ��䱣������
            Actor *_monkTang;

            //���actor�����еĽ�ɫ��Ϣ
            void printActors(string title,Actors & actors);
            
            //�齨�з�����monster����ȡ������enemies
            void buildEnemies(Actors & monsters,Actors & enemies);
            //�齨���ɡ��ҷ����з�
            void bulid(Actors & monks,Actors &enemies,Actors &gods);
            
            //�ж�ĳ����ɫ�Ƿ�Ϊ����
            bool isGod(Actor &actor);
            //�ж�ĳ����ɫ�Ƿ�Ϊ����
            bool isMonster(Actor &actor);
            
            //ץס�����أ����������ޣ�����������ޣ������ػᱻ�Ե�
            int captureTang(Actors &enemies,Actors &monks);
            //losers����
            void escape(Actors& winners,Actors &losers);
            //winners����losers
            void kill(Actors &winners,Actor & losers);
            //monks��enemies��ս��������ʵ������ֵ
            int fight(Actors &monks,Actors &enemies);
            //monksѰ��gods�İ��������ɹ��򷵻�false
            bool askForHelp(Actors &monks,Actors &gods);
            //winnersսʤlosers
            void win(Actors &winners,Actors &losers);

    public:
            Game(void);
            ~Game(void);
            //��ָ�����������ж�ȡ��ɫ��������ɫ
            int loadActors(istream &actorList);

            //��һ���ַ������ж�ȡ���ԣ���������ɫ
            Actor* createActor(string type,stringstream &parameters);
            //���ٵ�ָ���Ľ�ɫ
            void destroyActor(Actor *actor);
            

            //��ʼ��Ϸ
            void play(void);
            //��ʼ��Ϸ��ĳһ��
            void play(int level);
            //��ȡ��ǰ��
            int getLevel(void) const;
            //��ȡ������������
            int getDays(void) const;

            //���count��С����
            void createMonsters(int count);
            //actor����ȡ���Ŷ�
            void joinTravelers(Actor *actor);
};

#endif
