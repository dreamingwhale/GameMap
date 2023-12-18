#pragma once
class FMissile
{
public:
	int LocationX;
	int LocationY;

	FMissile();
	FMissile(const int& inputLocationX, const int& inputLocationY, int inputMissileNum);
	~FMissile();

	int getLocationX();
	void setLocationX(int inputLocationX);
	int getLocationY();
	void setLocationY(int inputlocationY);
	int move();
	int collision();

};

