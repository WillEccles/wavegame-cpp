#include "wavegame.h"
#include "player.h"
#include "trail.h"

const static float TICK_TIME = 0.0166666667f;

void draw(sf::RenderWindow& window) {
	window.clear(sf::Color::Black);

	for (auto& obj : game_objects)
		obj->draw(window);

	window.display();
}

bool tick(sf::Time elapsed) {
	if (elapsed.asSeconds() < TICK_TIME) return false;

	for (auto it = game_objects.begin(); it != game_objects.end(); ) {
		if ((*it)->garbage()) {
			(*it).reset();
			it = game_objects.erase(it);
		} else {
			(*it)->tick();
			if ((*it)->needsTrail()) {
				addGameObject(std::make_unique<wavegame::trail>((*it)->getPos(), (*it)->getSize(), (*it)->getColor()));
			}
			it++;
		}
	}

	return true;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Wavegame C++");
	addGameObject(std::make_unique<wavegame::player>(sf::Color(255, 0, 0)));
	// this ensures that the player is always the first thing in the array of objects

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time elapsed = clock.getElapsedTime();
		if (tick(elapsed)) {
			// draw in here, since this makes sure it only draws at 60fps
			draw(window);
			clock.restart();
		}
	}

	return 0;
}
