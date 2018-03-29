#ifndef TRAIL_H
#define TRAIL_H

#include "wavegame.h"
#include "gameobject.h"

class wavegame::trail : public wavegame::gameobject {
	private:
		float life = 0.05f;
		float alpha = 1.0;
		sf::RectangleShape trail_shape;
	public:
		trail(sf::Vector2f loc, sf::Vector2f s, sf::Color c, float lifespan = 0.05f): life(lifespan) {
			setPos(loc);
			setSize(s);
			setVel(0, 0);
			setColor(c);
			trail_shape = sf::RectangleShape(size);
			trail_shape.setPosition(pos);
		};
		void tick() {
			if (alpha > life) {
				alpha -= life - 0.001f;
				sf::Color c = getColor();
				c.a = clamp((int)(alpha*255.0f), 0, 255);
				setColor(c);
			} else {
				setGarbage(true);
			}
		};
		void draw(sf::RenderWindow& window) {
			trail_shape.setFillColor(getColor());
			window.draw(trail_shape);
		};
};

#endif
