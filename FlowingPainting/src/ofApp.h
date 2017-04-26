#pragma once

#include "ofMain.h"
#include "Particles.h"
#include "ofxGui.h"

#define MAXSIZE 5000 //最多的粒子数

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void setVectorField(); 
		ofVec2f getVec2fAt(ofVec2f pos);
		
		ofFbo fbo;

		ofFloatImage vectorField;//存储向量场

		vector<ofPtr<Particles>> particles;

		ofParameter<int> fieldSize;
		void fieldSizeChanged(int & fieldSize);

		ofxPanel gui;

		
};
