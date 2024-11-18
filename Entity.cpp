#include "Entity.h"


Entity::Entity(const string& name, const string& path, float x, float y, Vector2f scale)
    : texturePath(path), posX(x), posY(y), Scale(scale), sprite_name(name) {
}

Sprite Entity::getSprite() const {
	return sprite;
}

Vector2f Entity::getSpritePosition() const {
    return sprite.getPosition();
}

void Entity::setSpritePosition(float x, float y) {
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
}

Vector2f Entity::getSpriteScale() const {
    return sprite.getScale();
}

void Entity::setSpriteScale(Vector2f scale_vec) {
    Scale = scale_vec;
    sprite.setScale(Scale);
}

void Entity::setSpriteTexture() {
    auto texture = ResourceManager::loadTexture(sprite_name, texturePath);
    if (texture == nullptr) {
        std::cout << "Failed to load texture for entity from " << texturePath << std::endl;
        return;
    }
    sprite.setTexture(*texture);
}

Texture Entity::getSpriteTexture() {
    auto texture = ResourceManager::loadTexture(sprite_name, texturePath);
    if (texture != nullptr) {
        auto size = texture->getSize();
    }
    else {
        std::cout << "Erreur : la texture n'a pas été chargée correctement." << std::endl;
    }

	return *texture;
}

Vector2u Entity::getSpriteSize() {
	return getSpriteTexture().getSize();
}

void Entity::Initialize()
{
    setSpriteTexture();
    setSpritePosition(posX, posY);
    setSpriteScale(Scale);
}

void Entity::Update() {


}