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

////////////////�ⲿ����/////////////////
//�����滻�ַ���
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
    cout<<"�����μǡ���ʼ..."<<endl;
}
Game::~Game(void)
{
    //����
    map<string,Actor *>::iterator it;
    for(it=_actors.begin();it!=_actors.end();it++)
    {
        delete (*it).second;
    }
    cout<<"�����μǡ�������..."<<endl;
}
//���ļ��ж�ȡ��ɫ��
//�ļ���ʽ

//actor=<��ɫ��>,<�Ա�>,<����>
//weapon=<������>,<����>
int Game::loadActors(istream &actorList)
{
    Actor *actor = 0;
    while(!actorList.eof())
    {
        //��ȡ���е�һ��
        char line[256];
        actorList.getline(line,255);

        string s = line;
        //�հ��У�����
        if(s.empty())
            continue;
        //#Ϊע�ͱ�ǣ�����
        if(s[0] == '#')
            continue;
        //������=������
        int i =s.find("=");
        if(i<0)
        {
            continue;
        }
        //��ֳ�key=value
        string key = s.substr(0,i);
        string value =s.substr(i+1);

        //�������value
        value = replace(value,",","\n");
        stringstream ss(value);
        //����
        if(key =="weapon")
        {
            string name;
            int power;
            ss>>name>>power;
            Weapon weapon(name,power);
            (*actor)<<weapon;
        }
        //��ɫ
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

    //��ͨ��ɫ
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
//ɾ��ָ���Ľ�ɫ
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

    //�齨ȡ���ߵĶ���
    _travelers.clear();
    if(_actors.find("������")==_actors.end())
    {
        throw NoActor(*this,"������");
    }
    if(_actors.find("�����") == _actors.end())
    {
        throw NoActor(*this,"�����");
    }
    _monkTang = _actors["������"];
    _travelers.push_back(_monkTang);
    _travelers.push_back(_actors["�����"]);

    //��ʼ����
    for(int i =1;i<=LEVElS;i++)
    {
        cout<<endl<<"-------��"<<i<<"��------"<<endl<<endl;
        play(i);
    }
}
//ÿһ�غϵ����̣�
//
//���ִ�ס��ɮ�������ڼ��죨3~10�죩֮�ڳԵ������أ�
//ͽ���Ǿ���ɮ�����ʧ������Ҫ��������
void Game::paly(int level)
{
    _level = level;
    //ɸѡ�����е�����
    //���齨��ս˫��
    Actors gods;
    //�ҷ�
    Actors monks(_travelers);
    //�з�
    Actors enemies;
    build(monks,enemies,gods);

    int days = captureTang(enemies,monks);

    bool ok = false;
    for(int i =0;i<days;i++)
    {
        _days++;
        cout<<endl<<"----��"<<(i+1)<<"��-------"<<endl;

        //���н�ɫִ��onEveryDay
        map<string,Actor *>::iterator it;
        for(it = _actors.begin();it != _actors.end();it++)
        {
            Actor *actor = (*it).second;
            actor->onEveryDay(*this);
        }
    }
    //��ս
    int delta = fight(monks,enemies);
    //ʧ��
    if(delta<0)
    {
        
    }
}