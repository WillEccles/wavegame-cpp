#include "wavegame.h"
#include "player.h"

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
			delete (*it);
			it = game_objects.erase(it);
		} else {
			(*it)->tick();
			it++;
		}
	}

	return true;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Wavegame C++");
	_player = new wavegame::player(sf::Color(255, 0, 0));
	addGameObject(_player);

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time elapsed = clock.restart();
		tick(elapsed);
		draw(window);
	}

	return 0;
}
