#include"particles.h"

void Particles::destroy()
{
    if(durationCounter<2)
    {
        glPushMatrix();
        for(double i =0 ; i<2*PI;i+=PI/12)
        {
            glPushMatrix();
                glTranslatef(cos(i)*destroyTranslation, sin(i)*destroyTranslation,0);
                glScalef(destroySize, destroySize,1);

                Shapes::rect(destroyColor);
            glPopMatrix();
        }
        glPopMatrix();
        destroySize += 0.01;
        destroyTranslation += 0.08;
        if(destroySize>.1) destroySize = .1;
        if(destroyTranslation>1)
        {
            destroyTranslation =0;
            destroySize = 0;
            durationCounter += 0.5;
        }
    }
}
