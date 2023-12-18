#include "Player.h"
#include <iostream>

void FPlayer::Attack()
{

}

void FPlayer::Move(const int& addLocationX, const int& addLocationY)
{
	LocationX = LocationX + addLocationX;
	LocationY = LocationY + addLocationY;
}

FPlayer::FPlayer()
{
	HP = 100;
	MP = 100;
}

FPlayer::~FPlayer()
{
	std::cout << "Destructed" << std::endl;
}

int FPlayer::getLocationX()
{
	return LocationX;
}
int FPlayer::getLocationY()
{
	return LocationY;
}
void FPlayer::setLocationX(const int& inputX)
{
	LocationX = inputX;
}
void FPlayer::setLocationY(const int& inputY)
{
	LocationY = inputY;
}
char FPlayer::getShape()
{
	return Shape;
}