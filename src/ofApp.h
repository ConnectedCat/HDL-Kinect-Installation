#pragma once

#include "ofMain.h"
#include "ofxKinectForWindows2.h"
#include "Pigeon.h"
#include "Diamond.h"

#define PNUM 17                                          

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		
		ofxKFW2::Device kinect;

		int width = 1024;
		int height = 848;

		bool bFullscreen;

		ofVec3f rightHandPos;
		ofVec3f leftHandPos;
		ofVec3f leftFootPos;
		ofVec3f rightFootPos;

		vector<ofxKinectForWindows2::Data::Body> bodies;
		string posLOut, posROut, posBOut;

		deque<Pigeon> myPigeons;
		//Pigeon myPigeons[PNUM];
		ofVec3f positions[PNUM];

		vector<Diamond> diamonds;
};
