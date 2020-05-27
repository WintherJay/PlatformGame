#pragma once
#include "PlayableCharacter.h"

class CharacterOne : public PlayableCharacter {
public:

	CharacterOne();

	bool virtual handleInput();
};
