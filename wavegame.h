#ifndef WAVEGAME_H
#define WAVEGAME_H

#include <GLUT/glut.h>
#include <map>
#include <vector>

static const int SCREENWIDTH = glutGet(GLUT_SCREEN_WIDTH);
static const int SCREENHEIGHT = glutGet(GLUT_SCREEN_HEIGHT);

// store which keys are down at the moment
static std::map<unsigned int, bool> keys;
static bool isPlaying = true; // this should be changed as necessary

namespace wavegame {
	class gameObject;
	class player;
	class trail;
}

using namespace wavegame;

static std::vector<gameObject*> game_objects;
static wavegame::player *_player;

static void addGameObject(gameObject* obj) {
	game_objects.push_back(obj);
}

template<class T>
T clamp(T num, T min, T max) {
	if (num < min)
		return min;
	else if (num > max)
		return max;
	else
		return num;
};

// a class to hold colors, which makes this all easier to do
class color {
	private:
		float _r = 0.0f;
		float _g = 0.0f;
		float _b = 0.0f;
		float _alpha = 1.0f;
	public:
		// you can do 0.0-255.0, which will be converted to 0.0-1.0
		void set(float r, float g, float b, float a = 1.0f) {
			_r = clamp(r, 0.0f, 255.0f)/255.0f;
			_g = clamp(g, 0.0f, 255.0f)/255.0f;
			_b = clamp(b, 0.0f, 255.0f)/255.0f;
			_alpha = clamp(a, 0.0f, 1.0f);
		};
		color() {
			set(0.0f, 0.0f, 0.0f, 1.0f);
		};
		color(float r, float g, float b, float a = 1.0f) {
			set(r, g, b, a);
		};
		float getR() { return _r; };
		float getG() { return _g; };
		float getB() { return _b; };
		float getAlpha() { return _alpha; };
		float getR255() { return _r * 255.0f; };
		float getG255() { return _g * 255.0f; };
		float getB255() { return _b * 255.0f; };
		void setAlpha(float a) { _alpha = clamp(a, 0.0f, 1.0f); };
};

// x and y are top left, based on number of pixels
void drawRect(float x, float y, float w, float h, color c) {
	// define vertices counter-clockwise
	glBegin(GL_QUADS);
	glColor4f(c.getR(), c.getG(), c.getB(), c.getAlpha());
	glVertex2f(x, y);
	glVertex2f(x, y + h);
	glVertex2f(x + w, y + h);
	glVertex2f(x + w, y);
	glEnd();
};

// adapt the previous one to use ints which is just easier
void drawRect(int x, int y, int w, int h, color c) {
	drawRect((float)x, (float)y, (float)w, (float)h, c);
}

#endif
