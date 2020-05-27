#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character) {
	bool reachedGoal = false;
	// Make a rect for all parts
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// CharacterOne's collision detection
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;

	// Checking a couple of tiles above CharacterOne's head
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	// Making sure the game doesnt check positions lower than zero or higher than the end of the array
	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	// Checking whether the character has fallen off the map
	FloatRect level(0, 0,
		m_LM.getLevelSize().x * TILE_SIZE,
		m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level)) {
		// respawn the character
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}

	// Loop through all local blocks
	for (int x = startX; x < endX; x++) {
		for (int y = startY; y < endY; y++) {
			// Initialize starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Checks whether the character's head has been submerged in lava/water
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3) {
				if (character.getTop().intersects(block)) {
					character.spawn(m_LM.getStartPosition(), GRAVITY);

					
				}
			}
			// Is character colliding with a regular block
			if (m_ArrayLevel[y][x] == 1) {
				if (character.getRight().intersects(block)) {
					character.stopRight(block.left);
				} else if (character.getLeft().intersects(block)) {
					character.stopLeft(block.left);
				}
				if (character.getBottom().intersects(block)) {
					character.stopFalling(block.top);
				} else if (character.getTop().intersects(block)) {
					character.stopJump();
				}
			}

			

			// Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4) {
				// Character has reached the goal
				reachedGoal = true;
			}
		}
	}
	
	return reachedGoal;
}