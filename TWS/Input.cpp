#include "Engine.h"

void Engine::input() {
	Event event;

	while (m_Window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			// "Escape" Player input exits the game
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				m_Window.close();
			}
			// "Enter" Player input starts the level
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				m_Playing = true;
			}
			// Switch the camera focus between the two characters 
			if (Keyboard::isKeyPressed(Keyboard::Q)) {
				m_Character1 = !m_Character1;
			}
			// Switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				m_SplitScreen = !m_SplitScreen;
			}
		}

		// Handle input specific to the first character
		if (m_CharacterOne.handleInput()) {
			
		}
		// Handle input specific to the second character
		if (m_CharacterTwo.handleInput()) {
		
		}
	}
}