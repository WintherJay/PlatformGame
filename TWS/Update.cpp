#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds) {
	if (m_NewLevelRequired) {
		

		loadLevel();
	}

	if (m_Playing) {
		// Update both characters
		m_CharacterOne.update(dtAsSeconds);
		m_CharacterTwo.update(dtAsSeconds);

		// Detect collisions and see if characters have reached the end tile
		// The second part of the if condition is executed only when CharacterOne touches the home tile
		if (detectCollisions(m_CharacterOne) && detectCollisions(m_CharacterTwo)) {
			// New level required
			m_NewLevelRequired = true;

		}
		else {
			// Run bobs collision detection
			detectCollisions(m_CharacterTwo);
		}

		// Let bob and thomas jump on each others heads
		if (m_CharacterTwo.getBottom().intersects(m_CharacterOne.getTop())) {
			m_CharacterTwo.stopFalling(m_CharacterOne.getTop().top);
		}
		else if (m_CharacterOne.getBottom().intersects(m_CharacterTwo.getTop())) {
			m_CharacterOne.stopFalling(m_CharacterTwo.getTop().top);
		}

		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		if (m_TimeRemaining < 0) {
			m_NewLevelRequired = true;
		}
	}

	

	// Sets the appropriate view around the appropriate character
	if (m_SplitScreen) {
		m_LeftView.setCenter(m_CharacterOne.getCenter());
		m_RightView.setCenter(m_CharacterTwo.getCenter());
	} else {
		// Centre full screen around appropriate character
		if (m_Character1) {
			m_MainView.setCenter(m_CharacterOne.getCenter());
		} else {
			m_MainView.setCenter(m_CharacterTwo.getCenter());
		}
	}

	// Time to update the HUD?
	m_FramesSinceLastHUDUpdate++;
	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate) {
		// Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;
		// Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());
		// Update the level text
		ssLevel << "Level:" << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());
		m_FramesSinceLastHUDUpdate = 0;
	}

	
}