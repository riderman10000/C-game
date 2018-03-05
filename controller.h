#pragma once

#include"shapes.h"

#include<windows.h>

#include<GL/glut.h>
#include<GL/glu.h>
#include"text.h"
#include"control.h"
#include"background.h"


class Controller
{
private:
    float wait = 0;
public:
    float sunScaleChanger = 0.005;
    float currentScore;

    Controller();
    void renderStart();
    void renderBg();
    void button();
    void clicked();
    bool gameOver, gameRunning;

    Background bg;
    Control control;
};
