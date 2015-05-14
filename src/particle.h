#pragma once
#include "ofMain.h"


class particle {
  public:
    particle();

    void reset();
    void update();

    ofPoint pos;
    ofPoint vel;
    float ang;
};
