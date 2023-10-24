#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void Render(int PlayerLocationX, int PlayerLocationY, int GoalLocationX, int GoalLocationY, char PlayerShape, char GoalShape) {
	char Map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				Map[i][j] = '*';
			}
			else {
				Map[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == PlayerLocationX && i == PlayerLocationY) {
				cout << PlayerShape;
			}
			else if (j == GoalLocationX && i == GoalLocationY) {
				cout << GoalShape;
			}
			else {
				cout << Map[i][j];
			}

		}
		cout << endl;
	}

}
bool IsNotExceedMaxMin(const int Number,const char Key) {
	int Max = 8;
	int Min = 1;
	if (Number > 1 && (Key=='A'||Key=='a')) {
		return true;
	}else if (Number < 8 && (Key == 'D' || Key == 'd')) {
		return true;
	}
	else if (Number < 8 && (Key == 's' || Key == 'S')) {
		return true;
	}
	else if (Number > 1 && (Key == 'W' || Key == 'w')) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	int PlayerLocationX = 1;
	int PlayerLocationY = 1;
	int GoalLocationX = 8;
	int GoalLocationY = 8;
	char PlayerShape = 'P';
	char GoalShape = 'G';

	bool bIsRunning = true;

	Render(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, PlayerShape, GoalShape);
	while (bIsRunning) {
		int Key = _getch();
		if (Key == 'a' || Key == 'A'|| Key == 'd' || Key == 'D'|| Key == 'w' || Key == 'W'|| Key == 's' || Key == 'S') {
			system("cls");//해킹의 여지가 있으므로 사용하지 말것
		}
		if (Key == 'a' || Key == 'A')
		{
			cout << "왼쪽" << endl;
			IsNotExceedMaxMin(PlayerLocationX,Key) ? PlayerLocationX-- : PlayerLocationX;
			Render(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, PlayerShape, GoalShape);
		}
		else if (Key == 'd' || Key == 'D')
		{
			cout << "오른쪽" << endl;
			IsNotExceedMaxMin(PlayerLocationX,Key) ? PlayerLocationX++ : PlayerLocationX;
			Render(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, PlayerShape, GoalShape);
		}
		else if (Key == 'w' || Key == 'W')
		{
			cout << "위쪽" << endl;
			IsNotExceedMaxMin(PlayerLocationY,Key) ? PlayerLocationY-- : PlayerLocationY;
			Render(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, PlayerShape, GoalShape);
		}
		else if (Key == 's' || Key == 'S')
		{
			cout << "아랫쪽" << endl;
			IsNotExceedMaxMin(PlayerLocationY,Key) ? PlayerLocationY++ : PlayerLocationY;
			Render(PlayerLocationX, PlayerLocationY, GoalLocationX, GoalLocationY, PlayerShape, GoalShape);
		}
		else if (Key == 'q' || Key == 'Q') {
			cout << "종료";
			bIsRunning = false;
		}
		cout << PlayerLocationX << ',' << PlayerLocationY;

		COORD pos = { PlayerLocationX,PlayerLocationY };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	}




	return 0;
}
