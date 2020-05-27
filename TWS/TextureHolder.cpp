#include "TextureHolder.h"
#include "assert.h"

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename) {
	// Getting a reference to m_Texture using m_S_instance
	auto& m = m_s_Instance->m_Texture;
	

	// create an iterator to hold a key-value-pair (kvp) and search for the required kvp
	// using the passed in filename
	auto keyValuePair = m.find(filename);
	// auto is equivelant of map<string, Texture>::iterator
	

	if (keyValuePair != m.end()) {
	
		// return the texture,
		// the second part of the kvp, the texture

		return keyValuePair->second;
	} else {
		// filename not found
		// Create a new key value pair using the filename
		auto& texture = m[filename];
		// Load the texture from file
		texture.loadFromFile(filename);
		
		return texture;
	}
}