#pragma once

#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>

#include"shapes.h"
#include"color.h"
#include<math.h>

#define PI 301415926535

class Particles
{
public:
    float destroyTranslation,
    destroySize,
    durationCounter=0,
    elementX,elementY;

    void destroy();
    Color destroyColor;
};
