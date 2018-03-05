#pragma once

class Color
{
private:
    float red,green,blue;
public:
    void setColor(float r,float g,float b)
    {
        red = r;
        green = g;
        blue =b;
    }
    float getRed(){return red;}
    float getGreen(){return green;}
    float getBlue(){return blue;}
};
