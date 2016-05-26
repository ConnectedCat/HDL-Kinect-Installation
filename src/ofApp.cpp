#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(width, height);
	ofSetFrameRate(20);
	for (int i = 0; i<PNUM; i++) {
		positions[i].set(ofRandom(-340, ofGetWidth() + 340), ofGetHeight() - 63, ofRandom(-300, -100));
		Pigeon newPigeon;
		newPigeon.setup(positions[i]);
		myPigeons.push_back(newPigeon);
	}

	bFullscreen = false;

	kinect.open();
	kinect.initBodySource();
	kinect.initBodyIndexSource();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (bFullscreen) {
		ofHideCursor();
	}
	else {
		ofShowCursor();
	}
	kinect.update();

	bodies = kinect.getBodySource()->getBodies();
	for (auto body : bodies) {
		if (body.tracked) {
			leftHandPos = body.joints[JointType_HandLeft].getPosition();
			rightHandPos = body.joints[JointType_HandRight].getPosition();
			leftFootPos = body.joints[JointType_FootLeft].getPosition();
			rightFootPos = body.joints[JointType_FootRight].getPosition();

			rightHandPos.x = ofMap(rightHandPos.x, -0.8, 0.8, 0, width);
			leftHandPos.x = ofMap(leftHandPos.x, -0.8, 0.8, 0, width);
			rightFootPos.x = ofMap(rightFootPos.x, -0.8, 0.8, 0, width);
			leftFootPos.x = ofMap(leftFootPos.x, -0.8, 0.8, 0, width);


			rightHandPos.y = ofMap(rightHandPos.y, -0.8, 0.8, height, 0);
			leftHandPos.y = ofMap(leftHandPos.y, -0.8, 0.8, height, 0);
			rightFootPos.y = ofMap(rightFootPos.y, -0.8, 0.8, height, 0);
			leftFootPos.y = ofMap(leftFootPos.y, -0.8, 0.8, height, 0);

			for (int i = 0; i<PNUM; i++) {
				if (myPigeons[i].state != "dead") {
					auto xdistancelh = abs(myPigeons[i].position.x - leftHandPos.x);
					auto ydistancelh = abs(myPigeons[i].position.y - leftHandPos.y);
					auto xdistancerh = abs(myPigeons[i].position.x - rightHandPos.x);
					auto ydistancerh = abs(myPigeons[i].position.y - rightHandPos.y);
					auto xdistancelf = abs(myPigeons[i].position.x - leftFootPos.x);
					auto ydistancelf = abs(myPigeons[i].position.y - leftFootPos.y);
					auto xdistancerf = abs(myPigeons[i].position.x - rightFootPos.x);
					auto ydistancerf = abs(myPigeons[i].position.y - rightFootPos.y);

					if ((xdistancelh <= 150 && ydistancelh <= 150) || (xdistancerh <= 150 && ydistancerh <= 150) || (xdistancelf <= 150 && ydistancelf <= 150) || (xdistancerf <= 150 && ydistancerf <= 150)) {
						myPigeons[i].turn();
					}

					if ((xdistancelh <= 50 && ydistancelh <= 150) || (xdistancerh <= 50 && ydistancerh <= 150) || (xdistancelf <= 50 && ydistancelf <= 150) || (xdistancerf <= 50 && ydistancerf <= 150)) {
						if (myPigeons[i].state == "walking") {
							myPigeons[i].fly();
						}
						//if (myPigeons[i].state == "flying" && myPigeons[i].position.y < ofGetHeight() / 2) {
						//	myPigeons[i].turn();
						//	if (myPigeons[i].canShit) {
						//		Diamond diamond = myPigeons[i].shitDiamond();
						//		diamonds.push_back(diamond);
						//	}
						//}
					}

					//if ((xdistancelf <= 20 && ydistancelf <= 40) || (xdistancerf <= 20 && ydistancerf <= 40)) {
					//	myPigeons[i].splat();
					//	Pigeon corpse = myPigeons[i];
					//	myPigeons.erase(myPigeons.begin() + i);
					//	myPigeons.push_front(corpse);
					//}
				}
			}
		}
	}

	ofBackground(155);
	for (int i = 0; i<PNUM; i++) {
		myPigeons[i].update();
	}

	if (diamonds.size() > 0) {
		for (int i = 0; i < diamonds.size(); i++) {
			diamonds[i].update();
			if (diamonds[i].position.y >= ofGetHeight() + 400.0) {
				diamonds.erase(diamonds.begin() + i);
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!bFullscreen) {
		kinect.getBodyIndexSource()->draw(0, 0, width, height);
		//kinect.getBodySource()->drawProjected(0, 0, width, height, ofxKFW2::ProjectionCoordinates::DepthCamera);
	}
	else {
		kinect.getBodyIndexSource()->draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	}

	if (diamonds.size() > 0) {
		for (int i = 0; i < diamonds.size(); i++) {
			diamonds[i].display();
		}
	}
	for (int i = 0; i<PNUM; i++) {
		myPigeons[i].display();
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
		case 'f':
			bFullscreen = !bFullscreen;

			if (!bFullscreen) {
				ofSetWindowShape(width, height);
				ofSetFullscreen(false);
			}
			else {
				ofSetFullscreen(true);
			}
			break;
	}
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
