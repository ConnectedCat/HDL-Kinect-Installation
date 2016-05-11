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

	name = random_string(6);
}

void Diamond::display() {
	animation.display(position.x, position.y, position.z);
}

void Diamond::update() {
	if (position.y - animation.getHeight() >= ofGetHeight()) {
		velocity.set(0, 0, 0);
	}
	position = position + velocity;
}

void Diamond::fall() {
	speed = 16.0;
	velocity.set(0, speed, 0);
	animation.setup("Diamond/frame_", "png", 20, false, false);
}

string Diamond::random_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}