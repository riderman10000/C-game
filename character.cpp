#include"character.h"
#include"shapes.h"
#include<GL/glut.h>
#include<GL/glu.h>
#include<windows.h>
#include<cmath>
#include <iostream>

Character::Character()
{
    speed = .6;
    posX =8;
    bulletAtATime =0;
    reloader = 0;
    shoot = false;
    dead = false;
    shooter = 0;
    shootTextDuration = -1;
}

void Character::head()
{
    Color color;
    glPushMatrix();
        glTranslatef(-1,1.3,0);
        //glRotatef(15,0,0,1);
        glScalef(.5,.5,1);//////////////////////////////
        Shapes::circle(colorA);
    glPopMatrix();

    color.setColor(1,1,1);
    glPushMatrix();
        glTranslatef(-1,1.3,0);
        glScalef(.2,.2,1);
        Shapes::circle(color);
    glPopMatrix();


}
void Character::body()
{
    Color color;
    glPushMatrix();
        glTranslatef(-1,1.3,0);
        glScalef(1.5,1,1);
        glRotatef(90,0,0,1);
        Shapes::triangle(colorA);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.85,0.8,0);
        glScalef(1.5,1,1);
        Shapes::rect(colorA);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1,1.3,0);
        glScalef(2,1,1);
        glRotatef(90,0,0,1);
        Shapes::triangle(colorA);
    glPopMatrix();

    Text t;

    color.setColor(1,1,1);
    glPushMatrix();
        glTranslatef(-0.65,1,0);
        t.text(color,"ENEMY");
    glPopMatrix();


}

void Character::gun()
{
    Color color;
    color.setColor(1,1,1);
    glPushMatrix();
        glScalef(.5,.4,1);
        Shapes::rect(color);
    glPopMatrix();

    glTranslatef(.1,0.05,0);
    glPushMatrix();
        glScalef(.4,.3,1);
        Shapes::rect(colorA);
    glPopMatrix();
}

void Character::moveUp()
{
    if(posY<-3.9)
    {
        posY+=0.005;
    }
    else
    {
        goUp = false;
        goDown = true;
    }
}

void Character::moveDown()
{
    if(posY>-3.9)
    {
        posY-=0.005;
    }
    else
    {
        goUp = true;
        goDown = false;
    }
}

void Character::moveRight()
{
    if(posX<8)
    {
        posX+=0.005;
    }
    else
    {
        goRight = false;
        goLeft = true;
    }
}

void Character::moveLeft()
{
    if(posX>2)
    {
        posX-=0.005;
    }
    else
    {
        goRight = true;
        goLeft = false;
    }
}





Enemy::Enemy()
{
    speed=.6;
    posX= 8;
    bulletAtATime=0;
    reloader = 0;
    goLeft = true;
    shoot = false ;
    goRight = false;
    goUp = false;
    goDown = false ;
    dead = false;
    shooter = 0;
    shootTextDuration=-1;
}
void Enemy::render()
{
    glPushMatrix();
        bullet();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(posX,posY,0);
        glScalef(.5,.5,1);
        build();
    glPopMatrix();

    shooter += 0.001;
}

void Enemy::build()
{
    glPushMatrix();

        glPushMatrix();
            glTranslatef(0.2,0.4,0);
            //glRotatef(180,0,0,1);
            head();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(.2,.4,0);
            body();
        glPopMatrix();

        if(bulletAtATime==4)
            bulletAtATime=0;

        glPushMatrix();
            glTranslatef(-2.5,1.5,0);
            gun();
        glPopMatrix();

        glPopMatrix();
        if(shoot || shootTextDuration>0)
        {
            glPushMatrix();
                glTranslatef(-4,2,0);
                shootText.fire(colorA);
            glPopMatrix();
            shootTextDuration--;
        }
}

void Enemy::bullet()
{
    if(shoot==true&&bulletAtATime!=4)
    {
        Bullet bullet;
        bullet.heroX = posX;
        bullet.heroY = posY;
        bullet.Enemy = true;
        bullets.push_back(bullet);
        bulletAtATime++;
        shoot = false;
        shootTextDuration = 50;
    }
    for(int i=0;i<bullets.size();i++)
    {
        if(bullets[i].killer)
        {
            bullets.erase(bullets.begin()+i);
            continue;
        }
        Bullet current = bullets[i];
        glPushMatrix();
            glTranslatef(bullets[i].heroX,bullets[i].heroY,0);
            glScalef(.5,.5,1);
            glTranslatef(.1,1.3,0);
            glTranslatef(-2,.2,0);
            bullets[i].bulletBody();
        glPopMatrix();
        bullets[i].heroX -= 0.03;
        if(bullets[i].heroX<-12)
            bullets.erase(bullets.begin()+1);
    }
    shoot = false;
}

Hero::Hero()
{
    speed =2;
    posX =-8;
    posY = prevY = -3.5;
    bulletAtATime = 0;
    reloader = 0;
    dead = false;
    newBullet = false;
    shoot = false;
    life = 5;
    shootTextDuration = -1;
}
void Hero::body()
{
    Color color;
    glPushMatrix();
        glTranslatef(-1,1.3,0);
        glScalef(1.5,1,1);
        glRotatef(270,0,0,1);
        Shapes::triangle(colorA);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.85,0.8,0);
        glScalef(1.5,1,1);
        Shapes::rect(colorA);
    glPopMatrix();

    Text t;

    glPushMatrix();
        glTranslatef(0.65,1.3,0);
        glScalef(2,1,1);
        glRotatef(270,0,0,1);
        Shapes::triangle(colorA);
    glPopMatrix();

    color.setColor(1,1,1);
    glPushMatrix();
        glTranslatef(-0.65,1,0);
        t.text(color,"HERO");
    glPopMatrix();
}

void Hero::bullet()
{
    if(shoot == true &&bulletAtATime !=12)
    {
        Bullet bullet;
        bullet.heroX = posX;
        bullet.heroY = posY;

       /* if((fabs(posY+3.5))<0.001)
            bullets[0].push_back(bullet);
        else if((fabs(posY+4))<0.01)
            bullets[1].push_back(bullet);
        else if((fabs(posY+4.5))<0.01)
            bullets[2].push_back(bullet);
        else if((fabs(posY+5))<0.01)
            bullets[3].push_back(bullet);*/
        float f=4;
        for(int o = 0;o<20;o++)
        {
                if((fabs(posY-f))<0.01)
                bullets[o].push_back(bullet);
            f-=0.5;
        }
    }
        for(int i=0;i<20;i++) //change 4 to 20
        {
            for(int j=0;j<bullets[i].size();j++)
            {
                if(bullets[i][j].killer)
                {
                    bullets[i].erase(bullets[i].begin()+1);
                    continue;
                }
                Bullet current = bullets[i][j];
                glPushMatrix();
                    glTranslatef(bullets[i][j].heroX,bullets[i][j].heroY,0);
                    glScalef(.5,.5,1);
                    glTranslatef(.1,1.3,0);
                    glTranslatef(0,.2,0);
                    bullets[i][j].bulletBody();
                glPopMatrix();
                bullets[i][j].heroX+=0.08;
                if(bullets[i][j].heroX>=10)
                    bullets[i].erase(bullets[i].begin()+j);
            }
        }
        shoot = false;
}
void Hero::moveUp()
{
    if(posY<8)
    {
        posY += 0.5;
        prevY = posY;
    }
}

void Hero::moveDown()
{
    if(posY>-8)
    {
        posY -= 0.5;
        prevY = posY;
    }
}

void Hero::moveRight()
{
    if(posX<8)
    {
        posX += 0.1;
        prevX = posX;
    }
}
void Hero::moveLeft()
{
    if(posX>-8)
    {
        posX -= 0.1;
        prevX = posX;
    }
}

void Hero::build()
{
    glPushMatrix();
        glTranslatef(0.2,0.4,0);
        head();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.2,0.4,0);
        body();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.2,1.5,0);
        if(bulletAtATime == 12)
            bulletAtATime = 0;
    glPopMatrix();

    glPopMatrix();

    if(shoot || shootTextDuration>0)
    {
        glPushMatrix();
            glTranslatef(1,2,0);
            Text shootText;
            Color colorA;
            colorA.setColor(0.16,0.5,0.72);
            shootText.fire(colorA);
        glPopMatrix();
        shootTextDuration--;
    }
}

void Hero::render()
{
    glPushMatrix();
        bullet();
    glPopMatrix();
    if(!dead)
    {
        glPushMatrix();
            glTranslatef(posX,posY,0);
            glScalef(0.5,0.5,1);
            build();
        glPopMatrix();
    }
}
