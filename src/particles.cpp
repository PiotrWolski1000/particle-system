#include "particles.h"

Particles::Particles() {};
Particles::Particles(float masa = 1, ofVec3f pos = ofVec3f(0, 0, 0), ofVec3f vel = ofVec3f(0, 0, 0), ofVec3f force = ofVec3f(0, 0, 0), int width = 5) {
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

void Particles::setPos(ofVec3f r2)
{
	this->r.x = r2.x;
	this->r.y = r2.y;
	this->r.z = r2.z;
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
void Particles::setLifespan(double dt)
{
	this->lifespan = dt;
}
double Particles::getLifespan()
{
	return this->lifespan;
}
double Particles::getBornTime()
{
	return this->bornTime;
}
void Particles::setBornTime(double time)
{
	this->bornTime = time;
}
void Particles::move(double dt, Particles pivotPoint)
{
	//this->f.x = int(_GRAVITIONAL * (((this->m * pivotPoint.getMass())) / (this->r.x - pivotPoint.getPos().x)*(this->r.x - pivotPoint.getPos().x)));
	////this->f.y = int(_GRAVITIONAL * (((this->m * pivotPoint.getMass())) / (this->r.y - pivotPoint.getPos().y)*(this->r.y - pivotPoint.getPos().y)));
	//this->f.z = int(_GRAVITIONAL * (((this->m * pivotPoint.getMass())) / (this->r.z - pivotPoint.getPos().z)*(this->r.z - pivotPoint.getPos().z)));
	////this->f.x = 0;
	//this->f.y = 0;
	////this->f.z = 0;

	float masa2 = pivotPoint.getMass();
	ofVec3f pos2 = pivotPoint.getPos()-this->r;

	this->f.x = this->m * masa2 / pos2.x*pos2.x;
	//this->f.y = this->m * masa2 / pos2.y*pos2.y;
	this->f.z = this->m * masa2 / pos2.z*pos2.z;
	this->f.y = 0;

	if (pivotPoint.getPos().x < this->r.x)
		this->f.x = -this->f.x;
	if (pivotPoint.getPos().y < this->r.y)
		this->f.y = -this->f.y;
	if (pivotPoint.getPos().z < this->r.z)
		this->f.z = -this->f.z;

	//velocity update
	this->v.x += this->f.x * dt;
	this->v.y += this->f.y * dt;
	this->v.z += this->f.z * dt;

	//this->v.y = 0;
	this->v.y = this->v.y;
	//position update
	this->r.x += this->v.x * dt;
	//this->r.y += this->v.y * dt;
	this->r.z += this->v.z * dt;
	this->r.y = this->r.y;

	//PRZEPIS:
	//1- LICZYMY SILY
	//2- LICZYMY PREDKOSCI
	//3- ZMIENIAMY POLOZENIE
	//4- WROC DO PKT 1

	//rotation matrix
	//this->setPos(
	//	ofVec3f(((int(this->r.x - x))*cos(PI / 180 * alfa) + (int(this->r.y - y))*sin(PI / 180 * alfa) + x),//x
	//		abs((int(this->r.x - x))*sin(PI / 180 * alfa) - (int(this->r.y - y))*cos(PI / 180 * alfa - y))// , //y
	//		, z)//z
	//);//updates coordinates with given parameter

	//cout << "rx: " << this->r.x << ", ry: " << this->r.y << ", rz: " << this->r.z << "\n";
	//cout << "wartosc wektora sily: " << sqrt(int(this->f.x) ^ 2 + int(this->f.y) ^ 2)<<'\n';
	//cout << "vx: " << this->v.x << ", vy: " << this->v.y << ", vz: " << this->v.z << "\n";
	//cout << "fx: " << this->f.x << ", fy: " << this->f.y << ", fz: " << this->f.z << "\n";

	//char click = getchar();

};