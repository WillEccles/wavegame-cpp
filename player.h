#ifndef PLAYER_H
#define PLAYER_H

#include "wavegame.h"
#include "gameobject.h"
#include "trail.h"

class wavegame::player : public wavegame::gameobject {
	private:
		sf::RectangleShape player_shape;
	public:
		player(sf::Color pc) {
			setX(1280/2-10);
			setY(720/2-10);
			setColor(pc);
			player_shape = sf::RectangleShape(sf::Vector2f(20, 20));
			player_shape.setFillColor(pc);
		};
		void tick() {
			if (isPlaying) {
				setVelX(0 + (KEY_LEFT*-10) + (KEY_RIGHT*10));
				setVelY(0 + (KEY_UP*-10) + (KEY_DOWN*10));
				
				if (getVelX() != 0 || getVelY() != 0) {
					// add a trail
				}

				if (getVelX() != 0 && getVelY() != 0) {
					if (KEY_LEFT && KEY_UP) {
						setVelX(-8);
						setVelY(8);
					} else if (KEY_LEFT && KEY_DOWN) {
						setVelX(-8);
						setVelY(-8);
					} else if (KEY_RIGHT && KEY_UP) {
						setVelX(8);
						setVelY(8);
					} else if (KEY_RIGHT && KEY_DOWN) {
						setVelX(8);
						setVelY(-8);
					}
				}

				setX(clamp(getX() + getVelX(), 0, 1280-20));
				setY(clamp(getY() + getVelY(), 0, 1280-20));
			} else {
				setVelX(0);
				setVelY(0);
			}
		};
		void draw(sf::RenderWindow& window) {
			player_shape.setPosition(getX(), getY());
			window.draw(player_shape);
		};
};

#endif
