//
//  Animation.cpp
//  pigeonsAnimated
//
//  Created by Maxim Safioulline on 3/8/16.
//
//

#include "Animation.h"

Animation::Animation() {
}

void Animation::setup(string _imagePrefix, string _imageType, int _count, bool _randomized, bool _single) {
	imageCount = _count;
	running = true;
	singleRun = _single;
	images.clear();
	int startFrame = 0;
	if (_randomized) {
		int startFrame = int(ofRandom(imageCount));
	}
	
	for (int i = startFrame; i < imageCount; i++) {
		string filename = _imagePrefix + padded(ofToString(i), 4) + "." + _imageType;
		ofImage tempImage;
		tempImage.load(filename);
		tempImage.setImageType(OF_IMAGE_COLOR_ALPHA);
		images.push_back(tempImage);
	}
	for (int i = 0; i < startFrame; i++) {
		string filename = _imagePrefix + padded(ofToString(i), 4) + "." + _imageType;
		ofImage tempImage;
		tempImage.load(filename);
		tempImage.setImageType(OF_IMAGE_COLOR_ALPHA);
		images.push_back(tempImage);
	}
}

void Animation::update() {
	for (int i = 0; i < imageCount; i++) {
		images[i].mirror(false, true);
	}
}

void Animation::display(float _xpos, float _ypos, float _zpos) {
	//ofSetColor(255, 255, 255);
	if (running) {
		frame = (frame + 1) % imageCount;
		images[frame].setAnchorPercent(0.5, 0.5);
		images[frame].draw(_xpos, _ypos, _zpos);
		if ((singleRun) && (frame == 0)) {
			running = false;
		}
	}
	else {
		images[imageCount-1].draw(_xpos, _ypos, _zpos);
	}
	
}

void Animation::resize(int _newwidth, int _newheight) {
	for (int i = 0; i < imageCount; i++) {
		images[i].resize(_newwidth, _newheight);
	}
}

int Animation::getWidth() {
	return images[0].getWidth();
}

int Animation::getHeight() {
	return images[0].getHeight();
}


//private methods
string Animation::padded(string _original, int _spacesTotal) {
	string result = _original;
	int addThose = _spacesTotal - result.length();
	for (int i = 0; i<addThose; i++) {
		result = "0" + result;
	}
	return result;
}
