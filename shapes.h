#pragma once

#include "color.h"

class Shapes
{
public:
    static void rect(Color);
    static void rect(float x,float y, float w, float h,Color);
    static void circle(Color);
   //static void circle(float x, float y, float r,Color);
    static void triangle(Color);
    static void octagon(Color);
};
