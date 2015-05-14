#include "ofApp.h"

int num_particles = 100;
float res_grid = 20;
int den = 3;
float ran = 0.2;
float vis = 0.1;

void ofApp::setup(){
  p.resize(num_particles);
  for (int i=0;i < num_particles;i++) {
    p[i].ang = i*2*PI/num_particles;
    p[i].reset();
  }
  
  grid.resize(ofGetWidth()/res_grid);
  int ox = 0.5*(ofGetWidth()%int(res_grid));
  int oy = 0.5*(ofGetHeight()%int(res_grid));
  for(unsigned int i=0;i < grid.size();i++) {
    grid[i].resize(ofGetHeight()/res_grid);
    for(unsigned int j=0;j < grid[i].size();j++) {
     grid[i][j] = ofPoint(i*res_grid+ox, j*res_grid+oy);
    }
  }
}

void ofApp::update(){
  for (int i=0;i < p.size();i++) {
    p[i].update();
  }
  if (!visible) {
    p.resize(num_particles);
    for (int i=0;i < p.size();i++) {
      p[i].reset();
    }
  }
}

void ofApp::draw(){
  ofBackground(10, 10, 10);
  visible = false;
  for (unsigned int i=0;i < p.size();i++) {
    if (p[i].pos.x <= 0 || p[i].pos.x >= ofGetWidth() || 
        p[i].pos.y <= 0 || p[i].pos.y >= ofGetHeight()) continue;
    visible = true;
    int ax = den*floor(p[i].pos.x/(res_grid*den));
    int ay = den*floor(p[i].pos.y/(res_grid*den));
    cout << ax << " " << ay << "\n";
    for (int x=0;x < den;x++) {
      for (int y=0;y < den;y++) {
        // round can push over the index, but not under, so be safe and min
        ofPoint c = grid[min(int(grid.size()-1), ax+x)][min(int(grid[0].size()-1), ay+y)];
        int d = pow(p[i].pos.x-c.x, 2) + pow(p[i].pos.y-c.y, 2);
        ofSetColor(255, 255, 255, min(255.0, 255 * sqrt(2) * vis * res_grid/sqrt(d)));
        ofLine(c.x, c.y, p[i].pos.x, p[i].pos.y);
      }
    }
  }
}

void ofApp::keyReleased(int key) {
  int psize = p.size();
  p.resize(psize + num_particles);
  for (int i=0;i < num_particles;i++) {
    p[psize+i].ang = i*2*PI/num_particles;
    p[psize+i].reset();
  } 
}
