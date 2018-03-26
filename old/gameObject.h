#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "wavegame.h"

class wavegame::gameObject {
	float posX = 0.0f;
	float posY = 0.0f;
	float velX = 0.0f;
	float velY = 0.0f;
	bool isGarbage = false;
	color col;
	public:
		gameObject() {};
		virtual ~gameObject() {};
		virtual void draw() = 0;
		virtual void tick() = 0;
		virtual bool garbage() { return isGarbage; }; // whether or not this object can be deleted (useful for trails, etc)
		void setGarbage(bool g) { isGarbage = g; };
		void setX(float x) { posX = x; };
		void setY(float y) { posY = y; };
		void setVelX(float vx) { velX = vx; };
		void setVelY(float vy) { velY = vy; };
		float getX() { return posX; };
		float getY() { return posY; };
		float getVelX() { return velX; };
		float getVelY() { return velY; };
		color getColor() { return col; };
		void setColor(color newcol) { col = newcol; };
};

#endif
