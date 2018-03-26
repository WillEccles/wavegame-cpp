#ifndef WAVEGAME_H
#define WAVEGAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

/* Macros for determining keys pressed */
#define ISPRESSED(k) sf::Keyboard::isKeyPressed(k)
#define KEY_LEFT (ISPRESSED(sf::Keyboard::Left) || ISPRESSED(sf::Keyboard::A))
#define KEY_RIGHT (ISPRESSED(sf::Keyboard::Right) || ISPRESSED(sf::Keyboard::D))
#define KEY_UP (ISPRESSED(sf::Keyboard::Up) || ISPRESSED(sf::Keyboard::W))
#define KEY_DOWN (ISPRESSED(sf::Keyboard::Down) || ISPRESSED(sf::Keyboard::S))

namespace wavegame {
	class gameobject;
	class player;
	class trail;
};

using namespace wavegame;

static std::vector<gameobject*> game_objects;
static wavegame::player *_player;
static bool isPlaying = true;

static void addGameObject(gameobject* obj) {
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
}

#endif
