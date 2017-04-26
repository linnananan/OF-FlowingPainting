#include "Particles.h"



Particles::Particles()
{
	pos = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	color = getRandomColor();
	maxSpeed = ofRandom(5, 10);
	speed = ofVec2f(0, 0);
	life = ofRandom(1.0f, 2.0f);
	lifeRate = ofRandom(0.01f, 0.02f);
}


Particles::~Particles()
{
}

void Particles::update(ofVec2f vf)
{
	speed = maxSpeed * vf;
	pos += speed;
	life -= lifeRate;
}

void Particles::draw()
{
	ofPushStyle();
	ofSetColor(color);
	ofCircle(pos, 3);
	ofPopStyle();
}

void Particles::init()
{
	pos = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	color = color = getRandomColor();
	maxSpeed = ofRandom(5, 10);
	speed = ofVec2f(0, 0);
	life = ofRandom(1.0f, 2.0f);
	lifeRate = ofRandom(0.02f, 0.05f);
}

ofColor Particles::getRandomColor()
{
	int i = floor(ofRandom(0, 4.99));
	switch (i)
	{
	case 0:
		return ofColor(13, 19, 55);
	case 1:
		return ofColor(140, 175, 217);
	case 2:
		return ofColor(46, 72, 182);
	case 3:
		return ofColor(72, 109, 213);
	case 4:
		return ofColor(200, 228, 242);
	default:
		break;
	}
	return ofColor(255, 215, 67);
}

bool Particles::isDead()
{
	return pos.x < 0 || pos.x > ofGetWidth() || pos.y < 0 || pos.y>ofGetHeight() || life<=0;
}