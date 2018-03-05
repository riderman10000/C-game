#include"control.h"

#include<iostream>
#include"text.h"

Control::Control()
{
        pair <Color, Color> newPair;
    newPair.first.setColor(0.08,0.62,0.5);
    newPair.second.setColor(0.101,0.732,0.64);
    colors.push_back(newPair);
    newPair.first.setColor(0.55,0.26,0.67);
    newPair.second.setColor(0.61,0.34,0.71);
    colors.push_back(newPair);
    newPair.first.setColor(0.94,.73,.15);
    newPair.second.setColor(0.95,0.61,0.07);
    colors.push_back(newPair);
    newPair.first.setColor(0.90,0.49,0.13);
    newPair.second.setColor(0.82,0.32,0);
    colors.push_back(newPair);

    enemyDead = false;
    enemyRandomer = 0;
    enemyCreator = 0;
    currentColor = 0;
    enemyPosition = -3.5;
    score = 0;
    dynamic = false;
    newEnemyBullet = false;

}

void Control::createEnemy()
{
    if(((enemyRandomer == 0 || enemyCreator > enemyRandomer) && enemies.size() < 10) || dynamic == true){
        //cout << (enemyRandomer == 0 || enemyCreator > enemyRandomer) <<  (enemies.size() < 4) << (dynamic == true) << endl;
        enemyCreator = 0;

        if(currentColor > 3)
            currentColor = 0;
        enemyRandomer = rand()%10;

        if(dynamic == true){
            enemies[createOnPosition].colorA = colors[currentColor].first;
            enemies[createOnPosition].colorB = colors[currentColor].second;
            enemies[createOnPosition].posX = 15;
            enemies[createOnPosition].dead = false;
            dynamic = false;
        }else{
            Enemy newEnemy;
            newEnemy.posY = enemyPosition;
            //cout << enemyPosition << endl;
            newEnemy.posX = 15;
            newEnemy.colorA = colors[currentColor].first;
            newEnemy.colorB = colors[currentColor].second;
            enemies.push_back(newEnemy);
            enemyPosition += -0.5;
        //if(enemyPosition < -5.4) enemyPosition = -3.5;
        if(enemyPosition < -5.1) enemyPosition = -0.5;
        }

        currentColor++;
       // cout << "Yeah New One" << newEnemy.posY  << endl;

    }
    if(enemyCreator > enemyRandomer){
        enemyRandomer = 0;
        enemyCreator = 0;
    }
    enemyCreator += 0.01;
}

void Control::render()
{
    renderEnemy();
    if(!hero.dead)
        checkColision();
    writeScore();

    glPushMatrix();
        glTranslatef(8,5.3,0);
        heroLife();
    glPopMatrix();
}
void Control::writeScore()
{
    Color color;
    color.setColor(0.91,0.29,0.23);
    Text newScore;
    glPushMatrix();
        glTranslatef(8,5,0);
        newScore.score(color, (int)score);
    glPopMatrix();
}
void Control::renderEnemy()
{
    for(int i = 0; i<enemies.size(); i++)
    {
        if(!enemies[i].dead){
            enemies[i].render();
            enemies[i].shoot = false;
            if(enemies[i].goLeft == true)
                enemies[i].moveLeft();
            if(enemies[i].goRight == true)
                enemies[i].moveRight();
            if(enemies[i].shooter > 2)
            {
                enemies[i].shooter = 0;
                enemies[i].shoot = true;
                newEnemyBullet = true;
            }
        }
        else
        {
            dynamic =true;
            Particles particle;
            particle.elementX = enemies[i].posX;
            particle.elementY = enemies[i].posY;
            particle.destroyColor = enemies[i].colorA;
            particles.push_back(particle);
            createOnPosition = i;
        }
        if(abs(abs(hero.posY)-abs(enemies[i].posY)) < 0.4)
        {
            hero.render();
            if(hero.gotHit){
                Particles particle;
                Color color;
                color.setColor(0.95,0,0);
                particle.elementX = hero.posX;
                particle.elementY = hero.posY;
                particle.destroyColor = color;
                particles.push_back(particle);
                hero.gotHit = false;
            }
        }
         //cout << enemies[i].shooter << endl;
    }

    for(int i = 0; i<particles.size(); i++)
    {

        if(particles[i].durationCounter > 2)
        {
            particles.erase(particles.begin() + i);
        }
        else
        {
            glPushMatrix();
                glTranslatef(particles[i].elementX, particles[i].elementY, 0);
                particles[i].destroy();
            glPopMatrix();
        }
    }
    createEnemy();
}

void Control::checkColision ()
{
    Collision colt;
    colt.DeadEnemy(hero.bullets, enemies);
    colt.DeadHero(hero,enemies);
    if(colt.isDeadEnemy){
        score += 25;
        enemyDead = true;
    }else{
        score += 0.001;
    }
}
void Control::heroLife(){
    float x = 0;
    Color color;
    color.setColor(1,1,1);
    glPushMatrix();
    glScalef(.33,.4,1);
    glPushMatrix();
        for(int i = 0; i<5; i++){
            glPushMatrix();
                glTranslatef(x,0,0);
                Shapes::rect(color);
            glPopMatrix();
            x += 1;
        }
    glPopMatrix();
    glPopMatrix();
    color.setColor(0.9,0.29,0.23);
    glPushMatrix();
    glScalef(.3,.3,1);
    glTranslatef(-4.8,.15,0);
    glPushMatrix();
        for(int i = 0; i<hero.life; i++){
            glPushMatrix();
                glTranslatef(x,0,0);
                Shapes::rect(color);
            glPopMatrix();
            x += 1;
        }
    glPopMatrix();
    glPopMatrix();
}
