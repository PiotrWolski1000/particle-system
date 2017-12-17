#pragma once
#include <iostream>
#include "ofMain.h"
#include "particles.h"
#include "definitions.h"
#include "myImages.h"
#include <ctime>
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void createParticles();
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
		void init();
		
		std::vector<Particles> b;//we store our particle objects in here
		Particles a, a2;//rotate to this particles
		ofEasyCam cam;
		ofCamera camera;
		double t = 0.06;//our in-game time counter, we'are not starting from time 0.0
		void eraseParticleVector();
		//coordinates system axises, we want to show the lines of coordinates in running window
		ofPolyline xAxis;
		ofPolyline yAxis;
		ofPolyline zAxis;

		void drawCoordinates();
		//myImages images;//show image png? doesnt work
};
