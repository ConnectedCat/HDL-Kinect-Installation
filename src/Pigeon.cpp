//
//  Pigeon.cpp
//  pigeonsAnimated
//
//  Created by Maxim Safioulline on 3/8/16.
//
//

#include "Pigeon.h"

Pigeon::Pigeon() {
}

void Pigeon::setup(ofVec3f _pos) {
	position = _pos;
	canShit = true;
	walk();
	int coin = 1 + rand() % 2;
	if (coin == 1) {
		turn();
	}
}

void Pigeon::display() {
	animation.display(position.x, position.y, position.z);
}

void Pigeon::update() {
	if (!canShit && ofGetElapsedTimeMillis() > 1000) {
		canShit = true;
	}

	if (((position.x <= animation.getWidth() / 2 - rangeCoef) && velocity.x < 0) || ((position.x >= ofGetWidth() - animation.getWidth() / 2 + rangeCoef) && velocity.x > 0)) {
		turn();
	}
	if (position.y <= animation.getHeight() / 2) {
		velocity.y *= -1;
	}
	if ((position.y >= ofGetHeight() - animation.getHeight() / 2) && (state == "flying")) {
		walk();
	}
	if (position.z >= 0 || position.z <= -600) {
		velocity.z *= -1;
	}
	position += velocity;
}

void Pigeon::fly() {
	speed = 14.0;
	position.y -= 10;
	velocity.set(speed, -speed, -speed);
	animation.setup("Flight/flight1/frame_", "png", 20, true, false);
	state = "flying";
}

void Pigeon::walk() {
	speed = 4.0;
	velocity.set(speed, 0, 0);
	animation.setup("Walk/walk1/frame_", "png", 20, true, false);
	state = "walking";
}

void Pigeon::turn() {
	if (state != "dead") {
		animation.update();
		velocity.x *= -1;
	}	
}

void Pigeon::splat() {
	velocity.set(0, 0, 0);
	animation.setup("Splat/frame_", "png", 11, false, true);
	state = "dead";
}

Diamond Pigeon::shitDiamond() {
	canShit = false;
	ofResetElapsedTimeCounter();
	Diamond newDiamond;
	newDiamond.setup(position);
	return newDiamond;
}

void Pigeon::setState() {
}