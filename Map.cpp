#include "Map.h"

FMap::FMap()
{
}

FMap::~FMap()
{
}

int FMap::getLocationX()
{
	return LocationX;
}
int FMap::getLocationY()
{
	return LocationY;
}
bool FMap::getWallStatusByLocation(const int& inputX, const int& inputY)
{
	if (LocationX == inputX && LocationY == inputY)
	{
		return IsWall;

	}
}
void FMap::setLocationX(const int& inputX)
{
	LocationX = inputX;
}
void FMap::setLocationY(const int& inputY)
{
	LocationY = inputY;
}

void FMap::setWallToTrue()
{
	IsWall = true;
}
void FMap::setWallToFalse()
{
	IsWall = false;
}