#ifndef TRAIL_H
#define TRAIL_H

#include "wavegame.h"
#include "gameObject.h"

class wavegame::trail : public wavegame::gameObject {
	private:
		float h, w;
		float life = 0.05f; // length of its lifetime in ticks
		float alpha = 1.0f;
	public:
		trail(float posX, float posY, float height, float width, color c, float lifespan = 0.05f): h(height), w(width), life(lifespan) {
			setX(posX);
			setY(posY);
			setColor(c);
		};
		void tick() {
			// we just want to change the timer here
			if (alpha > life) {
				alpha -= life - 0.001f;
				color c = getColor();
				c.setAlpha(alpha);
				setColor(c);
			}	
			else {
				setGarbage(true);
			}
		};
		void draw() {
			drawRect(getX(), getY(), w, h, getColor());
		};
};

#endif
