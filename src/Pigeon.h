//
//  Pigeon.hpp
//  pigeonsAnimated
//
//  Created by Maxim Safioulline on 3/8/16.
//
//

#ifndef Pigeon_h
#define Pigeon_h

#include "ofMain.h"
#include "Animation.h"

class Pigeon {
public:
	void setup(ofVec3f _pos);
	void update();
	void display();

	void fly();
	void walk();
	void turn();
	void setState();

	float speed;

	ofVec3f position;
	ofVec3f velocity;

	Animation animation;

	string state = "walking";

	int rangeCoef = 340;
	bool flip = false;

	Pigeon();

private:
};


#endif /* Pigeon_h */
