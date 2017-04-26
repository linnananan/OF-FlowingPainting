#pragma once

#include "ofMain.h"
class Particles
{
public:
	Particles();
	~Particles();
	
	void update(ofVec2f vf);
	void draw();
	ofColor getRandomColor();
	void init();
	bool isDead();
	

public:
	float maxSpeed;
	ofVec2f pos;
	ofVec2f speed;
	ofFloatColor color;

	float life; //设置生命，遇到无法运动的情况时可即使消除
	float lifeRate;

};

