#include "Missile.h"

FMissile::FMissile()
{
	LocationX = 0;
	LocationY = 0;
}
FMissile::FMissile(const int& inputLocationX, const int& inputLocationY,int inputMissileNum)
{
	LocationX = inputLocationX;
	LocationY = inputLocationY;
}

FMissile::~FMissile()
{

}

int FMissile::getLocationX()
{
	return LocationX;
}

void FMissile::setLocationX(int inputLocationX)
{
	LocationX = inputLocationX;
}

int FMissile::getLocationY()
{
	return LocationY;
}

int FMissile::move()
{
	return 0;
}

int FMissile::collision()
{
	return 0;
}

void FMissile::setLocationY(int inputLocationY)
{
	LocationY = inputLocationY;
}
