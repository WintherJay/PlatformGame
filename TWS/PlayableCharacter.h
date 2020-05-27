#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {
protected:
	Sprite m_Sprite;

	float m_jumpDuration;

	bool m_IsJumping;
	bool m_IsFalling;

	bool m_leftPressed;
	bool m_rightPressed;

	float m_TimeThisJump;

	bool m_JustJumped = false;
private:
	float m_Gravity;
	float m_Speed = 400;
	Vector2f m_Position;

	// Where are the characters various body parts?
	FloatRect m_Bottom;
	FloatRect m_Top;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_Texture;
public:
	void spawn(Vector2f startPosition, float gravity);

	// pure virtual function
	bool virtual handleInput() = 0;
	// This class is now abstract and cannot be instanciated

	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite
	FloatRect getBottom();
	FloatRect getTop();
	FloatRect getRight();
	FloatRect getLeft();

	Sprite getSprite();

	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	Vector2f getCenter();

	void update(float elapsedTime);
};