#include "ofApp.h"
//--------------------------------------------------------------

//double _g = -9.81;

int _N = 100;//n value defines how many particles do we want to have

void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(255, 255, 255, 0);

	//init
	for (int i = 0; i < _N; i++) {
		
		int mass = ofRandom(1, 10);
		//int mass = 10;
		int radius = 5;
		
		int mRx = ofRandom(200, 800);
		int mRy = ofRandom(200, 800);
		int mRz = ofRandom(200, 800);	

		int mVx = ofRandom(20, 20);
		int mVy = ofRandom(20, 20);
		int mVz = 0;
	
		int mFx = 0;
		int mFy = 0;
		int mFz = 0;

		b.push_back(Particles(mass, ofVec3f(mRx, mRy, mRz), ofVec3f(mVx, mVy, mVz), ofVec3f(mFx, mFy, mFz), radius));
		b[i].sphere.setRadius(b[i].getRadius());
		b[i].setLifespan();
		//test-comment below, when must wait for spowning particles bc of writing info in cmd
		//std::cout <<"mass: "<<mass<< ", mrx: " << mRx << ", mRy: " << mRy << ", mRz: " << mRz<<"\n";

	}
	//blue sphere
	a = Particles(3, ofVec3f(500, 500, 500), ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), 20);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	this->t+=_DT;//krok czasowy z kazdym przebiegiem petli jest zwiekszany

	//particles move
	for (auto& p:b)
	{
		p.setLifespan();
		p.move(this->t, a);
	}
	//pivotPoint move
	a.setPosZ(int(a.getPos().z + 1));
}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	for (int i = 0; i < this->b.size(); i++) {
		
		cam.lookAt(ofVec3f(500, 500, 500), ofVec3f(1, 1, 1)); // funky

		//blue sphere
		ofSetColor(0, 0, 0, 255);
		a.sphere.setPosition(a.getPos().x, a.getPos().y, a.getPos().z);
		a.sphere.draw();
		//coordinates axis lines
		this->drawCoordinates();
		//particles
		//ofSetColor(128,128,128,b[i].getLifespan()/10.0 * 255);
		ofSetColor(128, 128, 128);
		b[i].sphere.setPosition(b[i].getPos().x, b[i].getPos().y, b[i].getPos().z);
		b[i].sphere.draw();

	}
	cam.end();
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

void ofApp::init()
{
}

void ofApp::drawCoordinates()
{
	//red color- x-axis
	ofSetColor(255, 0, 255);
	ofDrawLine(0, 0, 0, 10000, 0, 0);
	//green- y-axis
	ofSetColor(0, 255, 0);
	ofDrawLine(0, 0, 0, 0, 10000, 0);
	//yellow z-axis
	ofSetColor(234, 255, 0);
	ofDrawLine(0, 0, 0, 0, 0, 10000);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::createParticles() {
	
}