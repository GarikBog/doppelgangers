#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM



// OBJECT
Object::Object() {}



void Object::set_pos(std::pair<float, float> pos)
{
	x = pos.first;
	y = pos.second;

	sprite.setPosition({ x,y });
}

void Object::set_pos(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setPosition({ x,y });
}

void Object::set_x(float x)
{

	this->x = x;

	sprite.setPosition({ x,y });
}

void Object::set_y(float y)
{

	this->y = y;

	sprite.setPosition({ x,y });
}

void Object::set_scale(std::pair<int, int> size)
{
	width = size.first;
	height = size.second;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_scale(int width, int height)
{
	this->width = width;
	this->height = height;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_width(int width)
{
	this->width = width;

	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_height(int height)
{
	this->height = height;

	std::cout << sprite.getLocalBounds().width << ' ' << sprite.getLocalBounds().height;
	sprite.setScale({
		width / sprite.getLocalBounds().width,
		height / sprite.getLocalBounds().height});
}

void Object::set_texture(std::string texture_file)
{	
	this->texture_file = texture_file;
	if (!texture.loadFromFile("textures/objects/" + texture_file)) {
		texture.loadFromFile("textures/tech/error.jpg");
		this->texture_file = "textures/tech/error.jpg";
	}
	
	sprite.setTexture(texture);
}

void Object::set_texture_rect(sf::IntRect rect)
{

	sprite.setTextureRect(rect);
}

std::string Object::get_texture() const
{
	return texture_file;
}

std::pair<float, float> Object::get_pos() const
{
	return {x,y};
}

float Object::get_x() const
{
	return x;
}

float Object::get_y() const
{
	return y;
}

sf::FloatRect Object::get_collision() const
{
	return sprite.getGlobalBounds();
}

std::pair<int, int> Object::get_scale() const
{
	return {width,height};
}

int Object::get_width() const
{
	return width;
}

int Object::get_height() const
{
	return height;
}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

}

Object::Object(std::pair<float, float> pos,std::pair<int,int> size, std::pair<int, int> scale, std::string texture_file)
{
	set_pos(pos);
	set_texture_rect({ 0,0,size.first,size.second });
	set_scale(scale);
	set_texture(texture_file);

}
// OBJECT




//ClickableObject
bool ClickableObject::click(sf::Vector2i mouse_pos)
{

	return (
		mouse_pos.x > x &&
		mouse_pos.x < x + sprite.getGlobalBounds().width &&
		mouse_pos.y > y &&
		mouse_pos.y < y + sprite.getGlobalBounds().height
		);
}

ClickableObject::ClickableObject(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file,Log& log): 
	Object(pos,size,scale,texture_file),
	log(log)
{
	
}
//ClickableObject

