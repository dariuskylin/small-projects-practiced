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
//�޷��ҵ�ƥ�䶫��ɫ����
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
                cout<<"�޷�����ָ�������ͣ�"<<_type<<"!"<<endl;
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
                cout<<"ȱ�ٽ�ɫ��"<<_name<<"!"<<endl;
            }
};
//��ɱ��
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
                cout<<"�������ڵ�"<<_game.getLevel()<<"�ر�"<<
                    _monster->getName()<<"����!"<<endl;
            }
};
//�Ҳ����ɴ�����֣����ֱ�ȫ��������ˣ�
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
                cout<<"�ڵ�"<<_game.getLevel()<<"��ɱ�����е��ˣ�"<<
                    endl;
            }
}
#endif

