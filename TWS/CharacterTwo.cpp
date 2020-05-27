#include "CharacterTwo.h"
#include "TextureHolder.h"

CharacterTwo::CharacterTwo() {
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/CharacterTwo.png"));

	m_jumpDuration = .25;
}

bool CharacterTwo::handleInput() {
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		// Start a jump if not already jumping and if not falling
		if (!m_IsJumping && !m_IsFalling) {
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	} else {
		m_IsJumping = false;
		m_IsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		m_leftPressed = true;
	} else {
		m_leftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		m_rightPressed = true;
	} else {
		m_rightPressed = false;
	}

	return m_JustJumped;
}