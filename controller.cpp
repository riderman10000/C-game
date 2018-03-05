#include"controller.h"
Controller::Controller()
{
    gameOver = false;
    gameRunning = false;
}

void Controller::renderStart(){

    if(currentScore+100 < control.score){
        bg.overAllSpeed += 0.01;
        currentScore = control.score;
    }
    bg.animate(sunScaleChanger);
    bg.render((int)control.score);
    if(gameRunning)
    {
        control.render();

        if(control.hero.newBullet)
            control.hero.newBullet = false;
        if(control.newEnemyBullet)
            control.newEnemyBullet = false;
        if(control.enemyDead)
            control.enemyDead = false;
        //bg.render((int)control.score);

        //if(control.hero.gotHit)
    }
    else
    {
        renderBg();
        glPushMatrix();
            glTranslatef(2.6,-3.6,0);
        glPopMatrix();
    }

    if(control.hero.dead)
    {
        gameOver = true;
        gameRunning = false;
        if(wait > 5)
                wait = -1;
        else if( wait >= 0)
            wait += 0.05;
        if(bg.overAllSpeed > 0)
            bg.overAllSpeed -= (bg.overAllSpeed/2);
    }
}

void Controller::renderBg(){
    Color color;
    color.setColor(0.88,0.86,0.13);
    glPushMatrix();
        glTranslatef(-4.5,-4.5,0);
        glScalef(9,9,1);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor(0.22,0.12,0.90);
    glPushMatrix();
        glTranslatef(-4,-4,0);
        glScalef(8,8,1);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor(0.85,0.03,0.94);
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glScalef(2,0.5,1);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor(1,1,1);
    Text logo;
    glPushMatrix();
        glTranslatef(-1,2,0);
        logo.text(color, "shooter");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2,1.5,0);
        logo.text(color, "shoot the enemy");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.2,0);
        logo.text(color, "press space to START ");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.45,-1.5,0);
        logo.text(color, "Shoot : S");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.45,-2.3,0);
        logo.text(color, "Direction : Arrow Keys");
    glPopMatrix();

    if(gameOver){
        glPushMatrix();
            glTranslatef(-3.5,-3.5,0);
            logo.score(color,control.score);
        glPopMatrix();
    }
}

void Controller::clicked(){
    if(!gameRunning)
    {
        Control newAI;
        control = newAI;
        gameRunning = true;
        gameOver = false;
        wait = 0;
        bg.overAllSpeed = 0;
    }
}
