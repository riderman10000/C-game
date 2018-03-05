#include"text.h"
#include<cstdio>

#define SETCOLOR(color) color.getRed(), color.getGreen(), color.getBlue()

void Text::fire(Color color)
{
    int l,i;
    std::string st = "boom";
    l=st.size();
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glRasterPos3f(0,0,-5);
        for(int i=0;i<l;i++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,st[i]);
    glPopMatrix();
}

void Text::score(Color color, int score)
{
    int l;
    char st[50];
    snprintf(st,sizeof(st), "Score: %d",score);
    l=strlen(st);
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glRasterPos3f(0,0,-5);
        for(int i = 0; i<l;i++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,st[i]);
        glPopMatrix();
}

void Text::text(Color color, char st[])
{
    int l;
    l=strlen(st);
    glPushMatrix();
        glColor3f(SETCOLOR(color));
        glRasterPos3f(0,0,-5);
        for(int i = 0; i<l;i++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,st[i]);
        glPopMatrix();
}
