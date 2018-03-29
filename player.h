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
			setPos(1280/2-10, 720/2-10);
			setSize(20, 20);
			setVel(0, 0);
			setColor(pc);
			player_shape = sf::RectangleShape(getSize());
			player_shape.setFillColor(pc);
		};
		void tick() {
			if (isPlaying) {
				setVel(0 + (KEY_LEFT*-10) + (KEY_RIGHT*10),
						0 + (KEY_UP*-10) + (KEY_DOWN*10));
				
				if (getVel().x != 0 || getVel().y != 0)
					setTrailable(true);
				else
					setTrailable(false);

				if (getVel().x != 0 && getVel().y != 0) {
					if (KEY_LEFT && KEY_UP) {
						setVel(-8, -8);
					} else if (KEY_LEFT && KEY_DOWN) {
						setVel(-8, 8);
					} else if (KEY_RIGHT && KEY_UP) {
						setVel(8, -8);
					} else if (KEY_RIGHT && KEY_DOWN) {
						setVel(8, 8);
					}
				}

				setPos(clamp(getPos().x + getVel().x, 0, 1280-20),
						clamp(getPos().y + getVel().y, 0, 1280-20));
			} else {
				setVel(0, 0);
			}
		};
		void draw(sf::RenderWindow& window) {
			player_shape.setPosition(getPos());
			window.draw(player_shape);
		};
};

#endif
