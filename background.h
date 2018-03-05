#pragma once

#include"shapes.h"
#include"color.h"
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>

class Background
{
public:
    float hillx,sunScale,cloudx,cloudFarX,cloudNearX,treex;
    float overAllSpeed;

    Background();

    void render(unsigned int);
    void sun();
    void moon();
    void cloud();
    void tree();
    void animate(float);
    void bushes();
};
