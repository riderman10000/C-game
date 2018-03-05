#include"background.h"


Background::Background()
{
    hillx=cloudx=cloudFarX=cloudNearX=0,treex;
    sunScale =1;
}

void Background::render(unsigned int c)
{
    bool a = true;
    if(c/500)
        a= !a;
    if(a)
    {
        glPushMatrix();
            glTranslatef(-0,4,0);
        //glScalef(sunScale,sunScale,1);
            sun();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(cloudFarX,4.5,0);
            glScalef(0.8,0.8,1);
            cloud();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(cloudFarX+5,4.5,0);
            glScalef(0.8,0.8,1);
            cloud();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(cloudNearX+5,2,0);
            glScalef(1.2,1.2,1);
            cloud();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(treex+12,2,0);
            glScalef(1.2,1.2,1);
            bushes();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(treex+5,2,0);
            glScalef(1.2,1.2,1);
            bushes();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(treex+2,2,0);
            glScalef(1.2,1.2,1);
            bushes();
        glPopMatrix();
    }
    else if(!a)
    {
        glPushMatrix();
            glTranslatef(-0,4,0);
        //glScalef(sunScale,sunScale,1);
            moon();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(cloudFarX,4.5,0);
            glScalef(0.8,0.8,1);
            cloud();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(cloudFarX+5,4.5,0);
            glScalef(0.8,0.8,1);
            cloud();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(cloudNearX+5,2,0);
            glScalef(1.2,1.2,1);
            cloud();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(treex+12,2,0);
            glScalef(1.2,1.2,1);
            tree();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(treex+7,2,0);
            glScalef(1.2,1.2,1);
            tree();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(treex+5,2,0);
            glScalef(1.2,1.2,1);
            tree();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(treex+1,2,0);
            glScalef(1.2,1.2,1);
            tree();
        glPopMatrix();
    }
}
void Background::sun() /// original :- sun
{
    Color color;



    color.setColor(0.733,0.92,0.97);
     glPushMatrix();
        glTranslatef(-10,-10,0);
        glScalef(20,20,1);
        Shapes::rect(color);
    glPopMatrix();

/*
    glPushMatrix();
        glScalef(10,10,1);
        glTranslatef(-0.5,-0.4,0);
        Shapes::rect(color);
    glPopMatrix();
*/
    color.setColor(0.99,0.96,0.54);

    glPushMatrix();
        glScalef(1.5,1.5,1);
        glTranslatef(-0.155,-0.155,0);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor(1,0.94,0);

    glPushMatrix();
        Shapes::rect(color);
    glPopMatrix();
}

void Background::moon() /// originally name it moon
{
     Color color;

    color.setColor(1,1,1);

    glPushMatrix();
        glScalef(0.75,0.75,1);
        glTranslatef(-0.155,-0.155,0);
        Shapes::circle(color);
    glPopMatrix();

    color.setColor(1,0.94,1);

    glPushMatrix();
        glScalef(0.45,0.45,1);
        glTranslatef(-0.155,-0.155,0);
        Shapes::circle(color);
    glPopMatrix();

}

void Background::cloud()
{
    Color color;
    color.setColor(1,1,1);

    glPushMatrix();
        glTranslatef(.4,0,0);
        Shapes::rect(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(.5,.5,1);
        glTranslatef(0,0,0);
        Shapes::rect(color);

    glPopMatrix();

    glPushMatrix();
        glScalef(.5,.5,1);
        glTranslatef(2.5,0,0);
        Shapes::rect(color);
    glPopMatrix();
}
void Background::bushes()
{
        Color color;
    color.setColor(0.23,0.87,0.38);
    glPushMatrix();
        glScalef(1,1,1);
        glTranslatef(2.5,-2.3,0);
        Shapes::rect(color);
    glPopMatrix();
    glPushMatrix();
        glScalef(1,1,1);
        glTranslatef(2.9,-2,0);
        Shapes::rect(color);
    glPopMatrix();
     glPushMatrix();
        glScalef(1,1,1);
        glTranslatef(4.3,-2,0);
        Shapes::rect(color);
    glPopMatrix();
    glPushMatrix();
        glScalef(1,1.5,1);
        glTranslatef(3.5,-1.5,0);
        Shapes::rect(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(1,0.9,1);
        glTranslatef(4.5,-2.5,0);
        Shapes::rect(color);
    glPopMatrix();
    color.setColor(1,0,0);
    glPushMatrix();
        glTranslatef(2.85,-1.5,0);
        glScalef(0.1,0.1,1);
        Shapes::rect(color);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(3.5,-1.25,0);
        glScalef(0.1,0.1,1);
        Shapes::rect(color);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(4.2,-1.5,0);
        glScalef(0.1,0.1,1);
        Shapes::rect(color);
    glPopMatrix();
}
void Background::tree()
{
    Color color;
    color.setColor(0.52,0.14,0.12);
    glPushMatrix();
        glScalef(.5,2.5,1);
        glTranslatef(2.5,-1.5,0);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor(0.23,0.87,0.38);
    glPushMatrix();
        glScalef(2,2,1);
        glTranslatef(.5,-1,0);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor(0.20,1,0.20);
    glPushMatrix();
        glScalef(1.5,1.5,1);
        glTranslatef(.5,-0.8,0);
        Shapes::rect(color);
    glPopMatrix();


    color.setColor(0.4,1,0.4);
    glPushMatrix();
        glScalef(1.5,1.5,1);
        glTranslatef(0.25,-1.5,0);
        Shapes::rect(color);
    glPopMatrix();

}
void Background::animate(float sunScaleChanger)
{
    treex -= (0.003);
    cloudFarX -= 0.0005;
    cloudNearX -= 0.002;
    if(sunScale>1.3)
        sunScaleChanger *= -1;
    else if(sunScale<1)
        sunScaleChanger *= -1;
    sunScale += sunScaleChanger;
    if(hillx <-23.2)
        hillx = 16;
     if(treex <-23.2)
        treex = 16;
    if(cloudFarX<-23)
        cloudFarX =10;
    if(cloudNearX<-23)
        cloudNearX=10;
}
