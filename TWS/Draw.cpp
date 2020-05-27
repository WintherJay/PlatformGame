#include "Engine.h"

void Engine::draw() {
	// clear last frame
	m_Window.clear(Color::White);

	// update the shader parameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());

	if (!m_SplitScreen) {
		// switch to background view
		m_Window.setView(m_BGMainView);

		// draw background
		//m_Window.draw(m_BackgroundSprite);
		// Draw the background, complete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// switch to main view
		m_Window.setView(m_MainView);

		// draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// draw Both Characters
		m_Window.draw(m_CharacterOne.getSprite());
		m_Window.draw(m_CharacterTwo.getSprite());

	} else {

		// First draw CharacterOne's side of the screen
		// Switch to background view
		m_Window.setView(m_BGLeftView);

		// Draw the background
		//m_Window.draw(m_BackgroundSprite);
		// Draw the background, complete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_LeftView
		m_Window.setView(m_LeftView);

		// draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// draw both characters
		m_Window.draw(m_CharacterTwo.getSprite());
		m_Window.draw(m_CharacterOne.getSprite());

	

		// Draw CharacterTwo's side of the screen
		// Switch to background view
		m_Window.setView(m_BGRightView);

		// Draw the background
		//m_Window.draw(m_BackgroundSprite);
		// Draw the background, complete with shader effect
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		// Switch to m_RightView
		m_Window.setView(m_RightView);

		// draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw Both Characters
		m_Window.draw(m_CharacterOne.getSprite());
		m_Window.draw(m_CharacterTwo.getSprite());

	
	}

	//draw the HUD
	// switch to hud view
	m_Window.setView(m_HUDView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing) {
		m_Window.draw(m_Hud.getMessage());
	}

	m_Window.display();
}