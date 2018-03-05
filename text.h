#pragma once

#include"color.h"
#include<GL/glut.h>
#include<GL/glu.h>
#include<string>
#include<cstring>

class Text
{
  private:
      int duration;
  public:
    void fire(Color color);
    void score(Color color, int score);
    void text(Color color, char st[]);
};
