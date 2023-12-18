#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <mmsystem.h>
#include <sstream>
#include <array>
#include <list>
#include <thread>
#include <chrono>
#include <conio.h>
#include "Player.h"
#include "Slime.h"
#include "Goblin.h"
#include "Boar.h"
#include "Map.h"
#include "Missile.h"
#pragma comment(lib,"winmm.lib")

using namespace std;

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int Controller() {
	if (_kbhit()) {
		char key = _getch();
		switch (key) {
		case 'a': // 왼쪽 이동
			return 1;
		case 'd': // 오른쪽 이동
			return 2;
		case 'w': // 위로 이동
			return 3;
		case 's': // 아래로 이동
			return 4;
		case 'q': // 게임 종료
			return 0;
		case 'n': // 미사일 발사
			return 5;
		default:
			return -1;
		}
	}
	return -1;
}

void print(vector<FMap>vectorMap, FPlayer& player, FMissile& missile)
{
	for (int i = 0; i < vectorMap.size(); i++)
	{
		if (vectorMap.at(i).IsWall == true)
		{
			cout << '*';
		}
		else if (player.getLocationX() == vectorMap.at(i).getLocationX() && player.getLocationY() == vectorMap.at(i).getLocationY()) {
			cout << player.getShape();
		}
		else if (missile.getLocationX() == vectorMap[i].getLocationX() && missile.getLocationY() == vectorMap.at(i).getLocationY())
		{
			cout << 'M';
		}
		else
		{
			cout << ' ';
		}
		if (vectorMap.at(i).getLocationX() == 9)
		{
			cout << endl;
		}

	}
}

std::wstring s2ws(const std::string& str) {
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	std::wstring wstr(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &wstr[0], len);
	return wstr;
}

void RenderAndCompute(vector<FMap>vectorMap, FPlayer* player, FMissile* missile)
{
	bool IsWallStatusGottaMoveToWest = false;
	bool IsWallStatusGottaMoveToEast = false;
	bool IsWallStatusGottaMoveToNorth = false;
	bool IsWallStatusGottaMoveToSouth = false;
	bool IsPlaying = true;
	while (IsPlaying) {
		auto startTime = std::chrono::high_resolution_clock::now();

		system("cls");
		int controller = Controller();
		for (int i = 0; i < vectorMap.size(); ++i)
		{
			IsWallStatusGottaMoveToWest = vectorMap[i].getWallStatusByLocation(player->getLocationX() - 1, player->getLocationY());
			IsWallStatusGottaMoveToEast = vectorMap[i].getWallStatusByLocation(player->getLocationX() + 1, player->getLocationY());
			IsWallStatusGottaMoveToNorth = vectorMap[i].getWallStatusByLocation(player->getLocationX(), player->getLocationY() - 1);
			IsWallStatusGottaMoveToSouth = vectorMap[i].getWallStatusByLocation(player->getLocationX(), player->getLocationY() + 1);
		}
		cout << player->getLocationX() << endl;
		cout << player->getLocationY() << endl;
		cout << IsWallStatusGottaMoveToWest << endl;
		cout << IsWallStatusGottaMoveToEast << endl;
		cout << IsWallStatusGottaMoveToNorth << endl;
		cout << IsWallStatusGottaMoveToSouth << endl;
		// 입력 및 연산 로직
		if (controller == 1 && (player->getLocationX() > 0) && (IsWallStatusGottaMoveToWest == true))
		{

			player->Move(-1, 0);

		}
		else if (controller == 2 && (player->getLocationX() < 9) && (IsWallStatusGottaMoveToEast == false))
		{

			player->Move(1, 0);

		}
		else if (controller == 3 && (player->getLocationY() > 0) && (IsWallStatusGottaMoveToSouth == false))
		{

			player->Move(0, -1);

		}
		else if (controller == 4 && (player->getLocationY() < 9) && (IsWallStatusGottaMoveToNorth == false))
		{

			player->Move(0, 1);

		}
		else if (controller == 0) {
			IsPlaying = false;
			std::cout << "게임 종료" << std::endl;
			break;
		}
		if (controller == 5) {
			// 미사일 생성 로직
			missile->setLocationX(player->getLocationX());
			missile->setLocationY(player->getLocationX());
		}

		// 출력 로직
		print(vectorMap, *player, *missile);
		gotoxy(player->getLocationX(), player->getLocationY());

		// 매 초 딜레이를 위해 현재 시간과 시작 시간 비교
		auto endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsedTime = endTime - startTime;
		std::this_thread::sleep_for(std::chrono::milliseconds(200) - elapsedTime); // 0.2초에서 경과한 시간을 뺌
	}

}


int main()
{
	//STL, Template, overloading, name mangling
	vector<FMap>vectorMap;
	//맵을 백터에 저장
	FMap* map = new FMap;
	std::string SoundPath = "C:\\Work\\GameMap\\tetris.wav";

	// std::wstring으로 변환
	std::wstring wstr = s2ws(SoundPath);

	// LPCWSTR로 사용
	LPCWSTR soundFile = wstr.c_str();

	PlaySound(soundFile, NULL, SND_FILENAME | SND_ASYNC);
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			map->setLocationX(X);
			map->setLocationY(Y);
			if (X == 9 || X == 0 || Y == 9 || Y == 0)
			{
				map->setWallToTrue();
			}
			else
			{
				map->setWallToFalse();
			}
			//test 하나의 점을 set wall을 통해 벽으로 만들어보기
			if (X == 5 && Y == 6)
			{
				map->setWallToTrue();
			}
			vectorMap.push_back(*map);
		}
	}

	FPlayer* player = new FPlayer();
	FMissile* missile = new FMissile();


	cout << "welcome";
	RenderAndCompute(vectorMap, player, missile);


	delete map;
	map = nullptr;
	delete player;
	player = nullptr;
	delete soundFile;
	soundFile = nullptr;
	delete missile;
	missile = nullptr;

	return 0;
}
