#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdlib.h>
#include"color.h"
#include <iostream>
#include <cmath>
#include <mmsystem.h>

#include "shapes.h"
#include "background.h"
#include "character.h"
#include "control.h"
#include "text.h"
#include "controller.h"
#include "particles.h"

using namespace std;

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
#define SETCOLOR(color) color.Getred(), color.Getblue(), color.Getgreen()

float currentWidth = 1024;
float currentHeight = 600;

Controller controller;
Particles pr;

void changeSize(int w, int h)
{
    glutReshapeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutPositionWindow(50,50);
    if(h==0)
        h=1;
    float ratio = w*1.0/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);

    currentWidth =w;
    currentHeight= h;
    gluPerspective(100,ratio,1,100);
    glMatrixMode(GL_MODELVIEW);
}
void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    controller.renderStart();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        controller.control.hero.moveUp();
        break;
    case GLUT_KEY_DOWN:
            controller.control.hero.moveDown();
        break;
    case GLUT_KEY_LEFT:
        controller.control.hero.moveLeft();
        break;
    case GLUT_KEY_RIGHT:
        controller.control.hero.moveRight();
        break;
    default:
        break;
    }
}
void keys(unsigned char key, int x, int y)
{
    if(key == 's')
        controller.control.hero.shoot = true;
    else if(key==32)
        controller.clicked();
    else if(key==27)
    {
        std::cout<<"position of hero "<<controller.control.hero.posX<<" , "<<controller.control.hero.posY<<std::endl;
        glutLeaveGameMode();
        exit(1);
    }
}
void mouse(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        //if(button==GLUT_LEFT_BUTTON)
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    //enter full screen
    glutGameModeString("1024x600:32@60");

    glutEnterGameMode();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glClearColor(.167,.237,.254,1);

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(keys);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    glutMainLoop();
}
