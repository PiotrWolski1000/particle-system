#include "ofApp.h"
//--------------------------------------------------------------

//double _g = -9.81;

int _N = 10;//n value defines how many particles do we want to have

void ofApp::setup(){
	ofBackground(0, 0, 0, 0);
	//turn off ortho
	camera.disableOrtho();
	//ilosc fps w title bar
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	//inicjalizacja
	for (int i = 0; i < _N; i++) {
		
		int mass = ofRandom(1, 10);
		int radius = 10;
		
		//int mRx = ofRandom(int(1), ofGetWidth() - radius);
		//int mRy = ofRandom(int(1), ofGetHeight() - radius);
		int mRx = ofRandom(0, 100);
		int mRy = ofRandom(0, 100);
		int mRz = ofRandom(0, 100);


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
		std::cout << "mrx: " << mRx << ", mRy: " << mRy << ", mRz: " << mRz<<"\n";

	}
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
	for (int i = 0; i < this->b.size(); i++) {
		b[i].sphere.setPosition(b[i].getPos().x, b[i].getPos().y, b[i].getPos().y);
		
		cam.begin();
		ofSetColor(64, 64, 64, 127);
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::createParticles() {
	
}