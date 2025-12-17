//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
////Game Params: 
//const int BOARD_SIZE = 3;
//const char EMPTYY_CHAR = '_';
//const char PLAYER1_CHAR = 'X';
//const char PLAYER2_CHAR = 'O';
//
//// Game State:
//char BOARD[BOARD_SIZE][BOARD_SIZE];
//char CurrentPlayer = PLAYER1_CHAR;
//bool isGameFinished = false;
//int input_x = -1;
//int input_y = -1;
//
////Game Loop pattern 
//void Initialize();
//void GetInput();
//void Update();
//void Render();
//void Shutdown();
//
//bool IsCellFree(int x, int y);
//void PlaceMove();
//bool CheckRowColWin();
//bool CheckDiagonalWin();
//bool HasAnyEmptyCell();
//void SwitchPlayer();
//void ResetInput();
//
//int main()
//{
//	Initialize();
//
//	while (!isGameFinished) {
//		Render();
//		GetInput();
//		Update();
//	}
//	Render();
//	Shutdown();
//	return 0;
//}
//
//void Initialize() {
//	for (int i = 0; i < BOARD_SIZE; i++) {
//		for (int j = 0; j < BOARD_SIZE; j++) {
//			BOARD[i][j] = EMPTYY_CHAR;
//		}
//	}
//
//	CurrentPlayer = PLAYER1_CHAR;
//	isGameFinished = false;
//	input_x = -1;
//	input_y = -1;
//}
//
//void GetInput() {
//	int choice;
//	cin >> choice;
//
//	if (!cin || choice < 1 || choice > 9) {
//		cin.clear();
//		cin.ignore(1000, '\n');
//		input_x = input_y = -1;
//		return;
//	}
//
//	int index = choice - 1;
//	input_y = index / 3;
//	input_x = index % 3;
//}
//
//void Update() {
//	if (input_x == -1 || input_y == -1)
//		return;
//
//	if (!IsCellFree(input_x, input_y)) {
//		ResetInput();
//		return;
//	}
//
//	PlaceMove();
//
//	if (CheckRowColWin() || CheckDiagonalWin()) {
//		isGameFinished = true;
//		return;
//	}
//
//	if (!HasAnyEmptyCell()) {
//		isGameFinished = true;
//		CurrentPlayer = EMPTYY_CHAR; 
//		return;
//	}
//
//	SwitchPlayer();
//	ResetInput();
//}
//
//
//bool IsCellFree(int x, int y) {
//	return BOARD[y][x] == EMPTYY_CHAR;
//}
//
//void PlaceMove() {
//	BOARD[input_y][input_x] = CurrentPlayer;
//}
//
//bool CheckRowColWin() {
//	for (int i = 0; i < 3; i++) {
//		if (BOARD[i][0] == CurrentPlayer &&
//			BOARD[i][1] == CurrentPlayer &&
//			BOARD[i][2] == CurrentPlayer)
//			return true;
//
//		if (BOARD[0][i] == CurrentPlayer &&
//			BOARD[1][i] == CurrentPlayer &&
//			BOARD[2][i] == CurrentPlayer)
//			return true;
//	}
//	return false;
//}
//
//bool CheckDiagonalWin() {
//	if (BOARD[0][0] == CurrentPlayer &&
//		BOARD[1][1] == CurrentPlayer &&
//		BOARD[2][2] == CurrentPlayer)
//		return true;
//
//	if (BOARD[0][2] == CurrentPlayer &&
//		BOARD[1][1] == CurrentPlayer &&
//		BOARD[2][0] == CurrentPlayer)
//		return true;
//
//	return false;
//}
//
//bool HasAnyEmptyCell() {
//	for (int y = 0; y < 3; y++)
//		for (int x = 0; x < 3; x++)
//			if (BOARD[y][x] == EMPTYY_CHAR)
//				return true;
//	return false;
//}
//
//void SwitchPlayer() {
//	CurrentPlayer = (CurrentPlayer == PLAYER1_CHAR)
//		? PLAYER2_CHAR
//		: PLAYER1_CHAR;
//}
//
//void ResetInput() {
//	input_x = input_y = -1;
//}
//
//void Render() {
//	system("cls");
//
//	for (int y = 0; y < 3; y++) {
//		for (int x = 0; x < 3; x++) {
//			char c = BOARD[y][x];
//			if (c == EMPTYY_CHAR)
//				cout << " " << (y * 3 + x + 1) << " ";
//			else
//				cout << " " << c << " ";
//
//			if (x < 2) cout << "|";
//		}
//		if (y < 2) cout << "\n-----------\n";
//	}
//	cout << "\n\n";
//
//	if (!isGameFinished) {
//		cout << "Move player " << CurrentPlayer << ".\n";
//		cout << "Choose your position (1-9): ";
//	}		
//}
//
//void Shutdown() {
//	if (CurrentPlayer == EMPTYY_CHAR)
//		cout << "Draw!" << endl;
//	else
//		cout << "Player " << CurrentPlayer << " won!" << endl;
//}