#pragma once
class FSlime
{
public:
	FSlime();
	~FSlime();	//�Ҹ���
	int HP = 10;
	int MP = 10;
	char Shape = 'S';

	void Move();
	void Attack();
};

