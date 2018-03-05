#pragma once

#include<vector>
#include"bullet.h"
#include"color.h"
#include"text.h"

class Hero;
class Enemy;
class Character
{
public:
    float speed,posX,posY;
    bool shoot=false;

    int bulletAtATime,reloader;
    Color colorA,colorB;
    bool goLeft,goRight,goUp,goDown,dead;

    float shooter;
    int shootTextDuration;
    Text shootText;

    Character();
    void head();
    void body();
    void gun();




    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

};
class Hero:public Character
{
public:
    bool newBullet;
    float prevY,prevX;
    bool gotHit = false;
    int life;

    std::vector<Bullet> bullets[20];

    Hero();
    void body();

    void bullet(); ///

    void render();
    void build();

     void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();


};

class Enemy:public Character
{
public:
    Enemy();
    std::vector<Bullet> bullets;

    void bullet();

    void render();
    void build();

};

