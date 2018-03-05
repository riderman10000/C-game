#pragma once

#include"text.h"
#include"shapes.h"


class Bullet
{
public:
    Bullet();

    float   bulletX,bulletY,
            heroX,heroY;
      bool  Enemy,killer;

    void bulletBody();

};
