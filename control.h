#pragma once

#include "color.h"
#include <vector>
#include "character.h"
#include <math.h>
#include <cstdlib>

#include "collision.h"
#include "particles.h"

class Control
{
private:
    vector <pair <Color, Color> > colors;
    vector <Enemy> enemies;
    vector <Particles> particles;
    float enemyCreator;
    int currentColor;
    float enemyPosition;
    int enemyRandomer;
    int createOnPosition;
    bool dynamic;
public:
    bool newEnemyBullet;
    bool enemyDead;

    Control();
    Hero hero;
    void createEnemy();
    void renderEnemy();
    void render();
    void checkColision();
    void writeScore();
    void heroLife();
    float score;
};
