#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "wavegame.h"

class wavegame::gameobject {
	protected:
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::Vector2f size;
		bool isGarbage = false;
		sf::Color col;
		bool trailable = false;
	public:
		gameobject() {};
		virtual ~gameobject() {};
		virtual void draw(sf::RenderWindow&) = 0;
		virtual void tick() = 0;
		virtual bool garbage() { return isGarbage; };
		virtual bool needsTrail() { return trailable; };
		void setTrailable(bool t) { trailable = t; };
		void setGarbage(bool g) { isGarbage = g; };
		void setPos(sf::Vector2f p) { pos = p; };
		void setPos(float x, float y) { pos.x = x; pos.y = y; };
		void setVel(sf::Vector2f v) { vel = v; };
		void setVel(float x, float y) { vel.x = x; vel.y = y; };
		void setSize(sf::Vector2f s) { size = s; };
		void setSize(float w, float h) { size.x = w; size.y = h; };
		sf::Vector2f getPos() { return pos; };
		sf::Vector2f getVel() { return vel; };
		sf::Vector2f getSize() { return size; };
		sf::Color getColor() { return col; };
		void setColor(sf::Color newcol) { col = newcol; };
};

#endif
