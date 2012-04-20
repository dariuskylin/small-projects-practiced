/*
 * =====================================================================================
 *
 *       Filename:  gameexcept.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 03:30:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#ifndef _GAMEEXCEPT_H_
#define _GAMEEXCEPT_H_
#include<stdexcept>
using namespace std;

class Game;

class GameException :
    public runtime_error
{
    public:
        GameException()
            :runtime_error("GameException")
        {}
        ~GameException() throw()
        {
        }
        virtual void report() =0;
};
//无法找到匹配东角色类型
class NoSuchType :
    public GameException
{
    private:
            Game &_game;
            string _type;
    public:
            NoSuchType(Game &game,string type)
                :_game(game),_type(type)
            {
            }
            ~NoSuchType() throw ()
            {
            
            }
            void report()
            {
                cout<<"无法解析指定东类型："<<_type<<"!"<<endl;
            }
};
class NoActor : public GameException
{
    private:
            Game &_game;
            string _name;
    public:
            NoActor(Game &game,string name)
                :_game(game),_name(name)
            {
                
            }
            ~NoActor() throw ()
            {

            }
            void report()
            {
                cout<<"缺少角色："<<_name<<"!"<<endl;
            }
};
//被杀死
class BeKilled : public GameException
{
    private:
            Game &_game;
            Actor *_monster;
    public:
            BeKilled(Game &game,Actor *monster)
                :_game(game),_monster(monster)
            {
            
            }
            ~BeKilled() throw()
            {
                
            }
            void report()
            {
                cout<<"唐三藏在第"<<_game.getLevel()<<"回被"<<
                    _monster->getName()<<"吃了!"<<endl;
            }
};
//找不到可打的妖怪（妖怪被全部消灭光了）
class NoMoreEnemies : public GameException
{
    private:
            Game &_game;
    public:
            NoMoreEnemies(Game &game)
                :_game(game)
            {
            }
            ~NoMoreEnemies() throw()
            {

            }
            void report()
            {
                cout<<"在第"<<_game.getLevel()<<"回杀光所有敌人！"<<
                    endl;
            }
}
#endif

