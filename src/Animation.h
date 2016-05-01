//
//  Animation.hpp
//  pigeonsAnimated
//
//  Created by Maxim Safioulline on 3/8/16.
//
//

#ifndef Animation_h
#define Animation_h

#include "ofMain.h"

class Animation {
public:
	void setup(string _imagePrefix, string _imageType, int _count);
	void update();
	void display(float _xpos, float _ypos, float _zpos);
	int getWidth();
	int getHeight();

	vector <ofImage> images;
	int frameRate;

	Animation();

private:
	int imageCount;
	int frame;

	string padded(string _original, int _spacesTotal);
};

#endif /* Animation_h */
#pragma once
