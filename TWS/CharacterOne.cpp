#include "CharacterOne.h"
#include "TextureHolder.h"

CharacterOne::CharacterOne() {
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/CharacterOne.png"));

	m_jumpDuration = .45;
}

bool CharacterOne::handleInput() {
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		// Start a jump if not already jumping and not falling
		if (!m_IsJumping && !m_IsFalling) {
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	} else {
		m_IsJumping = false;
		m_IsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		m_leftPressed = true;
	} else {
		m_leftPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		m_rightPressed = true;
	} else {
		m_rightPressed = false;
	}

	return m_JustJumped;
}