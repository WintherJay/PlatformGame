#pragma once
#include "TextureHolder.h"
#include "PlayableCharacter.h"

class CharacterTwo : public PlayableCharacter {
public:
	CharacterTwo();

	bool virtual handleInput();
};