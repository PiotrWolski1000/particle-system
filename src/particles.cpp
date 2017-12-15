#include "particles.h"

Particles::Particles() {};
Particles::Particles(int masa = 1, ofVec3f pos = ofVec3f(0,0,0), ofVec3f vel = ofVec3f(0, 0, 0), ofVec3f force = ofVec3f(0, 0, 0), int width = 2) {
	this->m = masa;	
	this->r = pos;
	this->v = vel;
	this->f = force;
	this->radius = width;
}
int Particles::getRadius()
{
	return this->radius;
}
int Particles::getMass()
{
	return this->m;
}
ofVec3f Particles::getPos()
{
	return this->r;
}

ofVec3f Particles::getVel()
{
	return this->v;
}
ofVec3f Particles::getForce()
{
	return this->f;
}

void Particles::tempSetPos(ofVec3f r2)
{
	this->r.x = r2.x;
	this->r.y = r2.y;
	this->r.z = r2.z;//commented bc, we do not want to change z axis for now
}

void Particles::setPosX(int value)
{
	this->r.x = value;
}
void Particles::setPosY(int value)
{
	this->r.y = value;
}
void Particles::setPosZ(int value)
{
	this->r.z = value;
}

void Particles::setVelX(int value)
{
	this->v.x = value;
}
void Particles::setVelY(int value)
{
	this->v.y = value;
}
void Particles::setVelZ(int value)
{
	this->v.z = value;
}

void Particles::setForceX(int value)
{
	this->r.x = value;
}
void Particles::setForceY(int value)
{
	this->r.y = value;
}
void Particles::setForceZ(int value)
{
	this->r.z = value;
}

void Particles::move(double dt)
{
	//this->r.x = this->r.x + this->v.x * dt;
	//this->r.y = this->r.y + this->v.y * dt;
	//this->r.z = this->r.z + this->v.z * dt;
	
	//PRZEPIS:
	//1- LICZYMY SILY
	//2- LICZYMY PREDKOSCI
	//3- ZMIENIAMY POLOZENIE
	//4- WROC DO PKT 1

	//rotation to point, which coordinates we have below
	double x = 1000;
	double y = 1000;
	double z = 100;
	double alfa = 30;//kat o jaki obracamy

	//rotation- maybe change x to x_u and y to y_u? look: https://www.matematyka.pl/308613.htm

	ofVec3f r2 = ofVec3f(((int(this->r.x - x))*cos(PI / 180 * alfa) + (int(this->r.y - y))*sin(PI / 180 * alfa) + x),//x
		abs((int(this->r.x - x))*sin(PI / 180 * alfa) - (int(this->r.y - y))*cos(PI / 180 * alfa - y))// , //y
		, z);//z


	//ofVec3f r3 = ofVec3f(x, y, z);

	this->tempSetPos(r2);//updates coordinates with given parameter
	
	cout << "rx: " << this->r.x << ", ry: " << this->r.y<<", rz: "<<this->r.z<<"\n";
	//char click = getchar();

};