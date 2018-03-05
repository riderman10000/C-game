
#pragma once

#include <vector>
#include "bullet.h"
#include "character.h"
#include <cmath>
#include <iostream>

#define ERROR_AC 0.1
using namespace std;

class Collision
{
    public:
        Collision();
        void DeadEnemy(vector <Bullet>  (&bullets)[20], vector <Enemy> &enemies); //changed from 4 to 20
        void DeadHero(Hero &hero, vector <Enemy> &enemies);
        bool isDeadEnemy;
};
