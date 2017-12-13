#pragma once
#include <iostream>
#include "ofMain.h"
#include "particles.h"
#include "definitions.h"
#include "myImages.h"

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

		std::vector<Particles> b;//we store our particle object in here

		ofEasyCam cam;
		ofCamera camera;
		double t = 0;//our in-game time counter
		//myImages images;
};
