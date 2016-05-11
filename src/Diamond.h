//
//  Diamond.h
//  kinectActon
//
//  Created by Maxim Safioulline on 3/8/16.
//
//

#ifndef Diamond_h
#define Diamond_h

#include "ofMain.h"
#include "Animation.h"

class Diamond {
public:
	void setup(ofVec3f _pos);
	void fall();
	void update();
	void display();

	float speed;

	ofVec3f position;
	ofVec3f velocity;

	Animation animation;
	string name;

	Diamond();

private:
	string random_string(size_t length);
};
#endif /* Diamond_h */