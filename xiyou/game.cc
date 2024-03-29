/*
 * =====================================================================================
 *
 *       Filename:  game.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2012 01:05:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Darius-Kylin (DK), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include"game.h"
#include"gameexcept.h"
#include"funtors.h"

#include<ctime>
#include<cassert>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<typeinfo>

using namespace std;

#define LEVElS 81

////////////////外部函数/////////////////
//用以替换字符串
string replace(string &src,string find,string replacement)
{
    string dest;
    int i = 0;
    int len= find.length();
    while(true)
    {
        int start = i;
        i = src.find_first_of(find,i);
        if(i<0)
        {
            dest +=src.substr(start);
            break;
        }
        dest+=src.substr(start,i -start);
        dest+=replacement;
        i+=len;
    }
    return dest;
}
///////////////////Game/////////////////////
Game::Game(void)
{
    cout<<"《西游记》开始..."<<endl;
}
Game::~Game(void)
{
    //析构
    map<string,Actor *>::iterator it;
    for(it=_actors.begin();it!=_actors.end();it++)
    {
        delete (*it).second;
    }
    cout<<"《西游记》至此终..."<<endl;
}
//从文件中读取角色表
//文件格式

//actor=<角色名>,<性别>,<功力>
//weapon=<兵器名>,<威力>
int Game::loadActors(istream &actorList)
{
    Actor *actor = 0;
    while(!actorList.eof())
    {
        //读取其中的一行
        char line[256];
        actorList.getline(line,255);

        string s = line;
        //空白行，跳过
        if(s.empty())
            continue;
        //#为注释标记，跳过
        if(s[0] == '#')
            continue;
        //不包含=，跳过
        int i =s.find("=");
        if(i<0)
        {
            continue;
        }
        //拆分成key=value
        string key = s.substr(0,i);
        string value =s.substr(i+1);

        //继续拆分value
        value = replace(value,",","\n");
        stringstream ss(value);
        //兵器
        if(key =="weapon")
        {
            string name;
            int power;
            ss>>name>>power;
            Weapon weapon(name,power);
            (*actor)<<weapon;
        }
        //角色
        else
        {
            actor = createActor(key,ss);
        }
    }
    return _actors.size();
}
Actor* Game::createActor(string type,stringstream &parameters)
{
    Actor *actor=0;

    //普通角色
    if(type == "actor")
    {
        string name;
        bool gender;
        int power;
        parameters>>name>>boolalpha>>gender>>power;
        actor = new Actor(name,gender,power);
    }
    else if(type == "monk")
    {
        string name;
        string monkName;
        int power;
        parameters>>name>>monkName>>power;
        actor = new Monk(name,monkName,power);
    }
    else if(type =="god")
    {
        string name;
        bool gender;
        int power;
        parameters>>name>>boolalpha>>gender>>power;
        actor = new God(name,gender,power);
    }
    else if( type == "monster" )
    {
        string name;
        bool gender;
        int power;
        string place;
        parameters>>name>>boolalpha>>gender>>power>>place;
        actor = new Monster(name,gender,power,place);
    }
    else if(type == "follower" )
    {
        string name;
        int power;
        string place;
        string newName;
        string monkName;
        parameters>>name>>power>>place>>newName>>monkName;
        actor = new FollowerMonster(name,power,place,newName,monkName);
    }
    else 
    {
        throw NoSuchType(*this,type);
    }

    _actors[actor->getName()] = actor;
    return actor;
}
//删除指定的角色
void Game::destroyActor(Actor *actor)
{
    map<string,Actor *>::iterator it =_actors.find(actor->getName());
    if(it != _actors.end())
        _actors.erase(it);    
    Actors::iterator ita= find(_travelers.begin(),_travelers.end(),actor);
    if(ita != _travelers.end())
    {
        iter_swap(ita,_travelers.end()-1);
        _travelers.pop_back();
    }
    delete actor;
}
void Game::play(void)
{
    srand(time(0));
    _level = 0;
    _days = 0;
    _monkTang =0;

    //组建取经者的队伍
    _travelers.clear();
    if(_actors.find("唐三藏")==_actors.end())
    {
        throw NoActor(*this,"唐三藏");
    }
    if(_actors.find("孙悟空") == _actors.end())
    {
        throw NoActor(*this,"孙悟空");
    }
    _monkTang = _actors["唐三藏"];
    _travelers.push_back(_monkTang);
    _travelers.push_back(_actors["孙悟空"]);

    //开始闯关
    for(int i =1;i<=LEVElS;i++)
    {
        cout<<endl<<"-------第"<<i<<"回------"<<endl<<endl;
        play(i);
    }
}
//每一回合的流程：
//
//妖怪逮住唐僧，并会在几天（3~10天）之内吃掉唐三藏；
//徒弟们救唐僧，如果失败则需要求助神仙
void Game::paly(int level)
{
    _level = level;
    //筛选出所有的神仙
    //并组建作战双方
    Actors gods;
    //我方
    Actors monks(_travelers);
    //敌方
    Actors enemies;
    build(monks,enemies,gods);

    int days = captureTang(enemies,monks);

    bool ok = false;
    for(int i =0;i<days;i++)
    {
        _days++;
        cout<<endl<<"----第"<<(i+1)<<"天-------"<<endl;

        //所有角色执行onEveryDay
        map<string,Actor *>::iterator it;
        for(it = _actors.begin();it != _actors.end();it++)
        {
            Actor *actor = (*it).second;
            actor->onEveryDay(*this);
        }
    }
    //交战
    int delta = fight(monks,enemies);
    //失败
    if(delta<0)
    {
        
    }
}
