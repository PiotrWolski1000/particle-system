#include "ofApp.h"
//--------------------------------------------------------------

//double _g = -9.81;

int _N = 10;//n value defines how many particles do we want to have

void ofApp::setup(){
	ofBackground(0, 0, 0, 0);
	//ofEnableDepthTest();
	//turn off ortho
	//camera.disableOrtho();
	//idk yet
	//glDisable(GL_CULL_FACE);
	//ofSetSphereResolution(100);
	//fps in title bar
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	//init
	for (int i = 0; i < _N; i++) {
		
		int mass = ofRandom(1, 10);
		int radius = 10;
		
		//int mRx = ofRandom(int(1), ofGetWidth() - radius);
		//int mRy = ofRandom(int(1), ofGetHeight() - radius);
		
		int mRx = ofRandom(0, 1000);
		int mRy = ofRandom(0, 1000);
		//int mRz = ofRandom(0, 1000);
		
		//int mRx = 100;
		//int mRy = 100;
		int mRz = 100;

		//int mRy = 0;
		//int mRz = 0;

		int mVx = 0;
		int mVy = 0;
		int mVz = 0;
			
		int mFx = 0;
		int mFy = 0;
		int mFz = 0;

		//b[i].color.set(128, 128, 3);

		b.push_back(Particles(mass, ofVec3f(mRx, mRy, mRz), ofVec3f(mVx, mVy, mVz), ofVec3f(mFx, mFy, mFz), radius));
		b[i].sphere.setRadius(b[i].getRadius());
		
		//test-comment below, when must wait for spowning particles bc of writing info in cmd
		std::cout <<"mass: "<<mass<< ", mrx: " << mRx << ", mRy: " << mRy << ", mRz: " << mRz<<"\n";

	}
	//blue sphere
	//Particles a(3, ofVec3f(50, 50, 50), ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), 20);
	//a.sphere.setRadius(a.getRadius());

}

//--------------------------------------------------------------
void ofApp::update(){
	this->t+=_DT;//krok czasowy z kazdym przebiegiem petli jest zwiekszany
	
	for (auto& p:b)
	{
		p.move(this->t);
	}


}

//--------------------------------------------------------------
void ofApp::draw(){
	//images.draw(500, 500, 1024, 768);//rysowanie tla

	//blue sphere
	//ofSetColor(0, 0, 255, 127);//(64, 64, 64, 127)
	//a.sphere.setPosition(a.getPos().x, a.getPos().y, a.getPos().z);
	//a.sphere.draw();

	for (int i = 0; i < this->b.size(); i++) {
		cam.begin();
		
		this->drawCoordinates();

		ofSetColor(255, 255, 255, 127);//(64, 64, 64, 127)
		b[i].sphere.setPosition(b[i].getPos().x, b[i].getPos().y, b[i].getPos().z);
		b[i].sphere.draw();
		//ofSetColor(128,128,128);
		cam.end();
	}
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