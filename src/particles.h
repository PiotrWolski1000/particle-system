#include <ofVec3f.h>
#include "ofMain.h"
#include <math.h>
#include "definitions.h"//our consts

#pragma once
class Particles{

	int m;
	ofVec3f r;
	ofVec3f v;
	ofVec3f f;
	int radius;

public:
	Particles();
	Particles(int masa, ofVec3f r, ofVec3f v, ofVec3f f, int radius);

	//moving our particle
	void move(double dt);
	
	int getRadius();
	int getMass();

	ofVec3f getPos();
	ofVec3f getVel();
	ofVec3f getForce();

	void tempSetPos(ofVec3f);
	void setPosX(int);
	void setPosY(int);
	void setPosZ(int);

	void setVelX(int);
	void setVelY(int);
	void setVelZ(int);

	void setForceX(int);
	void setForceY(int);
	void setForceZ(int);

	ofSpherePrimitive sphere;//sphere object 
};




