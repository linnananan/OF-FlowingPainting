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

	float life; //���������������޷��˶������ʱ�ɼ�ʹ����
	float lifeRate;

};

