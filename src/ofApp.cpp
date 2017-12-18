#include "ofApp.h"
//--------------------------------------------------------------
int _N = 150;//n value defines how many particles do we want to have
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0, 0, 0, 0);

	
	//first inits
	a = Particles(100, ofVec3f(500, 500, 500), ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), 20);
	//a2 = Particles(100, ofVec3f(500, 500, 600), ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), 20);
	for (int i = 0; i < _N; i++) {
		
		//int mass = ofRandom(1, 10);
		int mass = ofRandom(1,10);
		int radius = 5;
		
		//positions
		int mRx = ofRandom(350, 650);
		int mRy = ofRandom(200, 700);
		int mRz = ofRandom(350, 650);	
		//velocities
		int mVx = ofRandom(50, 70);
		int mVy = ofRandom(50, 70);
		int mVz = 0;

		//forces, null at start
		int mFx = 0;
		int mFy = 0;
		int mFz = 0;

		b.push_back(Particles(mass, ofVec3f(mRx, mRy, mRz), ofVec3f(mVx, mVy, mVz), ofVec3f(mFx, mFy, mFz), radius));
		b[i].setBornTime(clock());
		b[i].setLifespan(ofRandom(12.0));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	this->t+=_DT;//time and time step, increased by every update loop step by constant value, check definitions.h

	for (auto& p:b)
	{
		p.move(this->t, a);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//erasing vector which forces are too big, equation for orbital speed?- sattelites
	//http://www.softschools.com/formulas/physics/orbital_velocity_formula/76/
	//http://www.fizykon.org/rpo/dyn_sila_odsrodkowa.htm

	this->eraseParticleVector();

	cam.begin();
	cam.lookAt(ofVec3f(500, 500, 500));//switch to blue sphere position
	for (int i = 0; i < this->b.size(); i++) {
		
		this->drawCoordinates();//coordinates axis lines
		//blue sphere
		ofSetColor(0, 0, 255, 0);
		a.sphere.setPosition(a.getPos().x, a.getPos().y, a.getPos().z);
		a.sphere.draw();

		//particles
		ofSetColor(255, 0, 0,b[i].getLifespan()/12.0 * 255);
		//ofSetColor(128, 128, 128);
		b[i].sphere.setRadius(5);
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
	for (int i = 0; i < (_N- this->b.size()); i++) {
		
		int mass = ofRandom(1, 10);
		//we want all the particles to be the same size, so radius should be const comparison to other parameters
		int radius = 5;
		//position, when make bigger range, the circles "may"(bc of random positions) be bigger
		int mRx = ofRandom(350, 650);
		int mRy = ofRandom(200, 700);
		int mRz = ofRandom(350, 650);
		//velocities, should be carefull about those, big parameter which sets path of motion, you may want to set start velocity vector at the beginning?
		int mVx = ofRandom(50, 70);
		int mVy = ofRandom(50, 70);
		int mVz = 0;//we rotate to this axis, because we want to have hurricane affect, that's why is 0 here

		//for new pieces in game forces are still 0s 
		int mFx = 0;
		int mFy = 0;
		int mFz = 0;

		b.push_back(Particles(mass, ofVec3f(mRx, mRy, mRz), ofVec3f(mVx, mVy, mVz), ofVec3f(mFx, mFy, mFz), radius));

		//here we add time to live of each particle, change to random from 
		b[i].setLifespan(ofRandom(12.0));
		b[i].setBornTime(clock());
	}
}

void ofApp::eraseParticleVector()
{//this function checks if lifespan of each particle is done, delete correctly count of particles and create the lost amount of particles as new ones
	for (int i = 0; i < this->b.size(); i++) {
		//cout << (clock() - b[i].getBornTime()) / 1000 << "sekund\n";
		if((clock() - b[i].getBornTime())/1000 > b[i].getLifespan()){
			this->b.erase((this->b.begin(), this->b.begin() + i));
		}
	}
	this->init();
}

void ofApp::drawCoordinates()
{
	//red color- x-axis
	ofSetColor(255, 0, 0);
	ofDrawLine(0, 0, 0, 100000, 0, 0);
	//green- y-axis
	ofSetColor(0, 255, 0);
	ofDrawLine(0, 0, 0, 0, 100000, 0);
	//blue z-axis
	ofSetColor(0, 0, 255);
	ofDrawLine(0, 0, 0, 0, 0, 100000);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
