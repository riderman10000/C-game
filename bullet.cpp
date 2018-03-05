#include"bullet.h"

#include<GL/glut.h>
#include<GL/glu.h>

Bullet::Bullet()
{
    bulletX = 0;
    bulletY = 0;
    Enemy =false;
    killer =false;
}

void Bullet::bulletBody()
{
    Color color;
    color.setColor(.255,0,0);

    glPushMatrix();
        if(Enemy == true)
            glRotatef(90,0,0,1);
        else
            glRotatef(270,0,0,1);
        glScalef(.2,.5,1);
        glTranslatef(bulletX,bulletY,0);

        Shapes::triangle(color);
    glPopMatrix();
}
