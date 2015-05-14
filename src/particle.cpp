#include "particle.h"

particle::particle() {}

void particle::reset() {
  pos.x = ofGetWidth()/2.0;
  pos.y = ofGetHeight()/2.0;
  vel.x = sin(ang) * 1.5 + 0.1*(ofRandom(1)-0.5);
  vel.y = cos(ang) * 1.5 + 0.1*(ofRandom(1)-0.5);
}

void particle::update() {
  pos += vel;
}
