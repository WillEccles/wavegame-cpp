#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "wavegame.h"

class wavegame::gameobject {
	int posX = 0;
	int posY = 0;
	int velX = 0;
	int velY = 0;
	bool isGarbage = false;
	sf::Color col;
	public:
		gameobject() {};
		virtual ~gameobject() {};
		virtual void draw(sf::RenderWindow&) = 0;
		virtual void tick() = 0;
		virtual bool garbage() { return isGarbage; };
		void setGarbage(bool g) { isGarbage = g; };
		void setX(int x) { posX = x; };
		void setY(int y) { posY = y; };
		void setVelX(int vx) { velX = vx; };
		void setVelY(int vy) { velY = vy; };
		int getX() { return posX; };
		int getY() { return posY; };
		int getVelX() { return velX; };
		int getVelY() { return velY; };
		sf::Color getColor() { return col; };
		void setColor(sf::Color newcol) { col = newcol; };
};

#endif
