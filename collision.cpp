#include "Collision.h"

Collision::Collision()
{
    isDeadEnemy = false;
}

/*void Collision::DeadEnemy(vector <Bullet>(&bullets)[20], vector <Enemy> &enemies) //change from 4 to 20
{
    for(int i = 0; i<enemies.size();i++)
    {
        if (!enemies[i].dead && abs(enemies[i].posY + 3.5) < ERROR_AC)
        {
            for(int j = 0; j<bullets[0].size(); j++)
            {
                if(abs(bullets[0][j].heroX - enemies[i].posX) < ERROR_AC)
                {
                    //cout << "Dead" << endl;
                    bullets[0][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }
        else if (!enemies[i].dead && abs(enemies[i].posY + 4) < ERROR_AC)
        {
            for(int j = 0; j<bullets[1].size(); j++)
            {
                if(abs(bullets[1][j].heroX - enemies[i].posX) < ERROR_AC)
                {
                    //cout << "Dead" << endl;
                    bullets[1][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }
        else if (!enemies[i].dead && abs(enemies[i].posY + 4.5) < ERROR_AC)
        {
            for(int j = 0; j<bullets[2].size(); j++)
            {
                if(abs(bullets[2][j].heroX - enemies[i].posX) < ERROR_AC)
                {
                    //cout << "Dead" << endl;
                    bullets[2][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }
        else if (!enemies[i].dead && abs(enemies[i].posY + 5) < ERROR_AC){
            for(int j = 0; j<bullets[3].size(); j++)
            {
                if(abs(bullets[3][j].heroX - enemies[i].posX) < ERROR_AC)
                {
                    //cout << "Dead" << endl;
                    bullets[3][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }

    }
}*/
void Collision::DeadEnemy(vector <Bullet>(&bullets)[20], vector <Enemy> &enemies) //change from 4 to 20
{
    float f=4;
    for(int h = 0;h<20;h++)
    {
         for(int i = 0; i<enemies.size();i++)
         {
            if(enemies[i].posY<0)
            {
                if(!enemies[i].dead&&abs(enemies[i].posY-f)<ERROR_AC)
                {
                    for(int j=0;j<bullets[h].size();j++)
                    {
                        if(abs(bullets[h][j].heroX-enemies[i].posX)<ERROR_AC)
                        {
                            bullets[h][j].killer=true;
                            enemies[i].dead=true;
                            isDeadEnemy = true;
                        }
                    }
                }
            }
        }
        f-=0.5;
    }
}


void Collision::DeadHero(Hero &hero, vector<Enemy> &enemies)
{
    for(int i = 0; i<enemies.size(); i++){
        for(int j = 0; j<enemies[i].bullets.size();j++){
            //if(!hero.jumper)
            {
                if(abs(enemies[i].bullets[j].heroY-hero.posY) < ERROR_AC)
                {
                    if(abs(enemies[i].bullets[j].heroX-hero.posX) < ERROR_AC)
                    {
                        if(hero.life == 1)
                            hero.dead = true;
                        else
                            hero.life--;
                        enemies[i].bullets[j].killer = true;
                        hero.gotHit = true;
                    }
                }
            }
            /*if(hero.jumper)
            {
               if(abs(enemies[i].bullets[j].heroY-hero.prevY) < ERROR_AC && abs(hero.prevY - hero.posY) < 1)
               {
                if(abs(enemies[i].bullets[j].heroX-hero.posX) < 1)
                    {

                    if(hero.life == 1)
                            hero.dead = true;
                        else
                            hero.life--;
                    enemies[i].bullets[j].killer = true;
                    hero.gotHit = true;
                }
               }
            }*/
        }
    }
}
