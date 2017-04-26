#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60.0f);
	vectorField.loadImage("field.jpg");
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);

	fieldSize.set("filed size", 30, 30, 80);
	fieldSize.addListener(this, &ofApp::fieldSizeChanged);
	gui.setup();
	gui.add(fieldSize);
	setVectorField();
	while (particles.size() < MAXSIZE)
	{
		ofPtr<Particles> pt;
		pt.reset(new Particles());
		particles.push_back(pt);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	float dt = ofGetLastFrameTime();
	fbo.begin();
	vector<ofPtr<Particles>>::iterator iter;
	for (iter = particles.begin(); iter != particles.end(); iter++)
	{
		(*iter)->update(getVec2fAt((*iter)->pos));
		if ((*iter)->isDead())
			(*iter)->init();
		else
			(*iter)->draw();
	}
	fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::fieldSizeChanged(int & fieldSize)
{
	
	setVectorField();
}

//设置向量场
void ofApp::setVectorField()
{
	int cols, rows;
	cols = floor(ofGetWidth() / fieldSize);
	rows = floor(ofGetHeight() / fieldSize);
	vectorField.resize(cols, rows);
	float x = 0;
	for (int i = 0; i < cols; i++)
	{
		float y = 0;
		for (int j = 0; j < rows; j++)
		{
			float theta = ofMap(ofNoise(x, y), 0, 1, 0, PI / 2.0f);
			ofFloatColor cr = ofFloatColor(0, 0, 0);
			ofVec2f v(cos(theta) - 0.5, sin(theta) - 0.5);
			cr.r = v.x + 0.5;
			cr.g = v.y + 0.5;
			vectorField.setColor(i, j, cr);
			y += 0.1;
		}
		x += 0.1;
	}
	vectorField.update();
	//重新设置向量场后清空fbo
	fbo.clear();
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
}

// 得到某点的向量
ofVec2f ofApp::getVec2fAt(ofVec2f pos)
{
	//将pos点所对应的向量限制在窗口中
	int i = ofWrap(floor(pos.x / fieldSize), 0, vectorField.getWidth()-1); 
	int j = ofWrap(floor(pos.y / fieldSize), 0, vectorField.getHeight()-1);
	ofFloatColor cr = vectorField.getColor(i , j);
	ofVec2f v(cr.r-0.5, cr.g-0.5);
	return v;
}