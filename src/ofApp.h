#pragma once

#include "ofMain.h"
#include "ofxKinectForWindows2.h"
#include "Pigeon.h"
#include "Diamond.h"

#define PNUM 17
#define DEPTH_WIDTH 512
#define DEPTH_HEIGHT 424
#define DEPTH_SIZE DEPTH_WIDTH * DEPTH_HEIGHT
#define APP_WIDTH DEPTH_WIDTH * 2
#define APP_HEIGHT DEPTH_HEIGHT * 2

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

		int width = 1024;
		int height = 848;

		bool bFullscreen;

		deque<Pigeon> myPigeons;
		ofVec3f positions[PNUM];
		vector<Diamond> diamonds;

		ofxKFW2::Device kinect;

		vector<ofxKinectForWindows2::Data::Body> bodies;
		//string posLOut, posROut, posBOut;
		ICoordinateMapper* coordinateMapper;

		ofImage bodyIndexImage;

		ofColor backgroundColor;
		ofColor bodyColor;

		vector<ofVec2f> colorCoords;
		int numBodiesTracked;
		bool bHaveAllStreams;

		ofVec3f rightHandPos;
		ofVec3f leftHandPos;
		ofVec3f leftFootPos;
		ofVec3f rightFootPos;
};
