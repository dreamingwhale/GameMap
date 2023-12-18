#pragma once
class FBoar
{
public:
	FBoar();
	~FBoar();

	int HP = 10;
	int MP = 10;
	char Shape = 'B';

	void Move();
	void Attack();

};

