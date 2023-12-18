#pragma once
class FGoblin
{
public:
	FGoblin();
	~FGoblin();
	int HP = 10;
	int MP = 10;
	char Shape = 'G';

	void Move();
	void Attack();

};

