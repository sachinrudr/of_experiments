#include "ofMain.h"
#include "ofApp.h"

int main(){
	ofSetupOpenGL(1900,1080,OF_FULLSCREEN);
	// ofSetupOpenGL(800,600,OF_WINDOW);
	ofRunApp( new ofApp());
}
