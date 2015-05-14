#pragma once

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void keyReleased(int key);
		
		vector <particle> p;
		vector <vector <ofPoint> > grid;
    bool visible;
};
