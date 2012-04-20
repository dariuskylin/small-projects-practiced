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

/////////////////外部函数///////////////////////
string replace(string &src,string find,string replacement);
/////////////////Game///////////////////////////
class Game
{
    private:
            //第几关
            int _level;
            //游戏所经历的总天数
            int _days;
            //所有角色
            map<string,Actor *> _actors;
            //取经团队
            Actors _travelers;
            //唐三藏会被经常用到，索性将其保存下来
            Actor *_monkTang;

            //输出actor中所有的角色信息
            void printActors(string title,Actors & actors);
            
            //组建敌方，从monster中提取妖怪至enemies
            void buildEnemies(Actors & monsters,Actors & enemies);
            //组建神仙、我方、敌方
            void bulid(Actors & monks,Actors &enemies,Actors &gods);
            
            //判断某个角色是否为神仙
            bool isGod(Actor &actor);
            //判断某个角色是否为妖怪
            bool isMonster(Actor &actor);
            
            //抓住唐三藏，并返回期限，超过这个期限，唐三藏会被吃掉
            int captureTang(Actors &enemies,Actors &monks);
            //losers逃跑
            void escape(Actors& winners,Actors &losers);
            //winners消灭losers
            void kill(Actors &winners,Actor & losers);
            //monks与enemies交战，并返回实力悬殊值
            int fight(Actors &monks,Actors &enemies);
            //monks寻求gods的帮助，不成功则返回false
            bool askForHelp(Actors &monks,Actors &gods);
            //winners战胜losers
            void win(Actors &winners,Actors &losers);

    public:
            Game(void);
            ~Game(void);
            //从指定的输入流中读取角色表，构建角色
            int loadActors(istream &actorList);

            //从一个字符串流中读取属性，并创建角色
            Actor* createActor(string type,stringstream &parameters);
            //销毁掉指定的角色
            void destroyActor(Actor *actor);
            

            //开始游戏
            void play(void);
            //开始游戏的某一关
            void play(int level);
            //获取当前关
            int getLevel(void) const;
            //获取所经历的天数
            int getDays(void) const;

            //添加count个小妖怪
            void createMonsters(int count);
            //actor加入取经团队
            void joinTravelers(Actor *actor);
};

#endif
