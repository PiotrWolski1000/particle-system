#include <ofVec3f.h>
#include <math.h>
#include "ofMain.h"
#include "definitions.h"//our consts

#pragma once
class Particles{

	float m;
	ofVec3f r;
	ofVec3f v;
	ofVec3f f;
	int radius;
	double lifespan;
	double bornTime;
	//plan
	//this t = clock - lifespan

public:
	Particles();
	Particles(float masa, ofVec3f r, ofVec3f v, ofVec3f f, int radius);
	~Particles() {};

	//moving our particle
	void move(double dt, Particles pivotPoint);
	
	int getRadius();
	int getMass();

	ofVec3f getPos();
	ofVec3f getVel();
	ofVec3f getForce();

	void setPos(ofVec3f);

	void setPosX(int);
	void setPosY(int);
	void setPosZ(int);

	void setVelX(int);
	void setVelY(int);
	void setVelZ(int);

	void setForceX(int);
	void setForceY(int);
	void setForceZ(int);

	void setLifespan(double);
	double getLifespan();
	double getBornTime();
	void setBornTime(double);

	ofSpherePrimitive sphere;//our sphere object 
};




