#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startingPosition, float gravity) {
	// place the player at the starting position
	m_Position.x = startingPosition.x;
	m_Position.y = startingPosition.y;

	// init gravity
	m_Gravity = gravity;

	// move sprite in position
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::update(float elapsedTime) {
	if (m_rightPressed) {
		m_Position.x += m_Speed * elapsedTime;
	}
	if (m_leftPressed) {
		m_Position.x -= m_Speed * elapsedTime;
	}

	// hnadle jumping
	if (m_IsJumping) {
		m_TimeThisJump += elapsedTime;

		// is the jump going upwards or downwards
		if (m_TimeThisJump < m_jumpDuration) {
			// move up at 2x gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else {
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}

	// applying gravity
	if (m_IsFalling) {
		m_Position.y += m_Gravity * elapsedTime;
	}

	// update the rect for all body parts
	FloatRect r = getPosition();
	// Feet
	m_Bottom.left = r.left + 3;
	m_Bottom.top = r.top + r.height - 1;
	m_Bottom.width = r.width - 6;
	m_Bottom.height = 1;
	// Head
	m_Top.left = r.left;
	m_Top.top = r.top + (r.height * .3);
	m_Top.width = r.width;
	m_Top.height = 1;
	// Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;
	// Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	// Move the sprite into position
	m_Sprite.setPosition(m_Position);
}

FloatRect PlayableCharacter::getPosition() {
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter() {
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
	);
}

FloatRect PlayableCharacter::getBottom() {
	return m_Bottom;
}

FloatRect PlayableCharacter::getTop() {
	return m_Top;
}

FloatRect PlayableCharacter::getLeft() {
	return m_Left;
}

FloatRect PlayableCharacter::getRight() {
	return m_Right;
}

Sprite PlayableCharacter::getSprite() {
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position) {
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void PlayableCharacter::stopRight(float position) {
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position) {
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopJump() {
	// Stop a jump early
	m_IsJumping = false;
	m_IsFalling = true;
}