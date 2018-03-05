#include <GL/glut.h>
#include <GL/glu.h>
#include<windows.h>
#include<math.h>

#include"shapes.h"

#define SETCOLOR(color) color.getRed(), color.getGreen(), color.getBlue()
#define PI 3.1415926535

void Shapes::rect(Color color)
{
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glBegin(GL_POLYGON);
            glVertex3f(0,0,-5.0);
            glVertex3f(1,0,-5.0);
            glVertex3f(1,1,-5.0);
            glVertex3f(0,1,-5.0);
        glEnd();
    glPopMatrix();
}

void Shapes::rect(float x, float y, float w, float h,Color color)
{
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glBegin(GL_POLYGON);
            glVertex3f(x,y,-5.0);
            glVertex3f(x+w,y,-5.0);
            glVertex3f(x+w,x+h,-5.0);
            glVertex3f(x,y+h,-5.0);
        glEnd();
    glPopMatrix();
}
void Shapes::circle(Color color)
{
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glBegin(GL_POLYGON);
        for(double i =0 ; i<2*PI;i+=PI/24)
            glVertex3f(cos(i)*1,sin(i)*1,-5.0);
        glEnd();
    glPopMatrix();
}
void Shapes::triangle(Color color)
{
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glBegin(GL_POLYGON);
            glVertex3f(-1,0,-5.0);
            glVertex3f(1,0,-5.0);
            glVertex3f(.02,1,-5.0);
            glVertex3f(0,1,-5.0);
        glEnd();
    glPopMatrix();
}
void Shapes::octagon(Color color)
{
    float angle = 0.0;
    float dAngle = PI/4.0;
    float x,y;
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glBegin(GL_POLYGON);
        for(int i=0;i<8;i++)
        {
            double theta = i*2.0*PI/8.0;
            x =cos(theta);
            y = sin(theta);
            glVertex3f(x,y,-5.0);
        }
        glEnd();
    glPopMatrix();
}
