#include "Engine.h"

Engine::Engine() {
	// Get screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y), "Thomas was Alone", Style::Fullscreen);

	// Initialise fullscreen view
	m_MainView.setSize(resolution);
	m_HUDView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// Initialise splitscreen views
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_RightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BGLeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_BGRightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	// load 2 shaders (1 vertex, 1 fragment)
	m_RippleShader.loadFromFile("shaders/vertShader.vert", "shaders/rippleShader.frag");

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Load the texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");


}

void Engine::run() {
	// timing
	Clock clock;

	while (m_Window.isOpen()) {
		Time dt = clock.restart();

		//update total game time
		m_GameTimeTotal += dt;

		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}