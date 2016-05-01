//
//  Diamond.cpp
//  kinectAction
//
//  Created by Maxim Safioulline on 3/8/16.
//
//

#include "Diamond.h"

Diamond::Diamond() {
}

void Diamond::setup(ofVec3f _pos) {
	position = _pos;
	fall();
}

void Diamond::display() {
	animation.display(position.x, position.y, position.z);
}

void Diamond::update() {
	if (position.y - animation.getHeight() >= ofGetHeight()) {
		velocity.set(0, 0, 0);
	}
	position += velocity;
}

void Diamond::fall() {
	speed = 16.0;
	velocity.set(0, speed, 0);
	animation.setup("Diamond/frame_", "png", 20);
}