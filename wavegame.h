#ifndef WAVEGAME_H
#define WAVEGAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

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

static std::vector<std::unique_ptr<gameobject> > game_objects;
static bool isPlaying = true;

static void addGameObject(std::unique_ptr<gameobject> obj) {
	game_objects.push_back(std::move(obj));
}

template<class T, class U, class V>
T clamp(T num, U min, V max) {
	if (num < (T)min)
		return (T)min;
	else if (num > (T)max)
		return (T)max;
	else
		return num;
}

#endif
