#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "wavegame.h"
#include "gameObject.h"
#include "trail.h"

class wavegame::player : public wavegame::gameObject {
	public:
		player(color pc) {
			setX(1280.0f/2.0f-10.0f);
			setY(720.0f/2.0f-10.0f);
			setColor(pc);
		};
		void tick() {
			if (isPlaying) {
				setVelX(0.0f + (keys['a']*-10.0f) + (keys['d']*10.0f));
				setVelY(0.0f + (keys['s']*-10.0f) + (keys['w']*10.0f));
				
				setX(clamp(getX() + getVelX(), 0.0f, 1280.0f-20.0f));
				setY(clamp(getY() + getVelY(), 0.0f, 720.0f-20.0f));

				if (getVelX() != 0.0f || getVelY() != 0.0f) {
					// add a trail to the player
					addGameObject(new wavegame::trail(getX(), getY(), 20.0f, 20.0f, getColor()));
				}

				// make sure diagonals aren't supidy fast
				if (getVelX() != 0.0f && getVelY() != 0.0f) {
					// these are all hardcoded so that we're not doing any math every tick
					if (keys['a'] && keys['w']) {
						setVelX(-8.509f);
						setVelY(8.509f);
					} else if (keys['a'] && keys['s']) {
						setVelX(-8.509f);
						setVelY(-8.509f);
					} else if (keys['d'] && keys['w']) {
						setVelX(8.509f);
						setVelY(8.509f);
					} else if (keys['d'] && keys['s']) {
						setVelX(8.509f);
						setVelY(-8.509f);
					}
				}
			} else {
				setVelX(0.0f);
				setVelY(0.0f);
			}
		};
		void draw() {
			drawRect(getX(), getY(), 20.0f, 20.0f, getColor());
		};
};

#endif
