#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "CharacterTwo.h"
#include "CharacterOne.h"
#include "LevelManager.h"
#include "HUD.h"

using namespace sf;

class Engine {
private:
	// initialise texture holder
	TextureHolder th;

	// initialise both Characters
	CharacterOne m_CharacterOne;
	CharacterTwo m_CharacterTwo;


	// initialise level manager 
	LevelManager m_LM;



	// Initialise HUD
	HUD m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// Adding gravity to the game
	const int GRAVITY = 300;

	// initialise render window
	RenderWindow m_Window;

	// initialise main views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HUDView;

	// Declare/initialise a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// declare a shader for the background
	Shader m_RippleShader;

	// bool to check if the game is currently playing
	bool m_Playing = false;

	// Is character 1 or 2 the camera focus
	bool m_Character1 = true;

	// start in fullscreen mode
	bool m_SplitScreen = false;

	// time left in level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;
	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	// A vertex array for the level tiles
	VertexArray m_VALevel;

	// A 2d array with the levels
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;

	// Texture for the level tiles
	Texture m_TextureTiles;

	
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a new level
	void loadLevel();

	
	bool detectCollisions(PlayableCharacter& character);


public:
	// constructor
	Engine();

	
	void run();
};