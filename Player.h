#pragma once

//namespace Namespace
//{
class FPlayer
{
public:
	FPlayer();
	~FPlayer();

	int LocationX = 5;
	int LocationY = 8;
	int HP = 100;
	int MP = 100;
	char Shape = 'P';

	int getLocationX();
	int getLocationY();
	void setLocationX(const int& inputX);
	void setLocationY(const int& inputY);
	char getShape();
	void Attack();
	void Move(const int& inputAddLocationX, const int& inputAddLocationY);
};

//}

