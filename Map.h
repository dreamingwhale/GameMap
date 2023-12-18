#pragma once
class FMap
{
public:
	FMap();
	~FMap();
	int LocationX = 0;
	int LocationY = 0;
	bool IsWall = false;

	int getLocationX();
	int getLocationY();
	bool getWallStatusByLocation(const int& inputX, const int& inputY);
	void setLocationX(const int& inputX);
	void setLocationY(const int& inputY);
	void setWallToTrue();
	void setWallToFalse();
};