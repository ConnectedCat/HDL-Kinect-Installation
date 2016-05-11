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
	void setup(string _imagePrefix, string _imageType, int _count, bool _randomized, bool _single);
	void update();
	void display(float _xpos, float _ypos, float _zpos);
	void resize(int _newwidth, int _newheight);

	int getWidth();
	int getHeight();

	vector <ofImage> images;
	int frameRate;
	bool running;
	bool singleRun;

	Animation();

private:
	int imageCount;
	int frame;

	string padded(string _original, int _spacesTotal);
};

#endif /* Animation_h */
#pragma once
