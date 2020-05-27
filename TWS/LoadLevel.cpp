#include "Engine.h"

void Engine::loadLevel() {
	m_Playing = false;

	// delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i) {
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	// Loads the next 2d array with the map for the level and repopulates the vertex array
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	// new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	// Spawn both characters
	m_CharacterOne.spawn(m_LM.getStartPosition(), GRAVITY);
	m_CharacterTwo.spawn(m_LM.getStartPosition(), GRAVITY);

	//Making sure levels dont infinitely loop
	m_NewLevelRequired = false;
}