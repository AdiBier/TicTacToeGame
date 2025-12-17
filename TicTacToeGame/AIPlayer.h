#pragma once
#include "Board.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class AIPlayer {
public:
    AIPlayer() { srand((unsigned) time(nullptr)); }

    void MakeAIMove(Board& board, int& moveX, int& moveY, char aiSymbol, char humanSymbol) {
        if (TryWin(board, moveX, moveY, aiSymbol))
            return;
        if (TryWin(board, moveX, moveY, humanSymbol)) {
            return;
        }
        if (TakeCenter(board, moveX, moveY))
            return;
		TakeAny(board, moveX, moveY);
    }

private: 
    bool TryWin(Board& board, int& moveX, int& moveY, char aiSymbol) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (board.IsCellFree(x, y)) {
                    board.Place(x, y, aiSymbol);
                    if (board.CheckWin(aiSymbol)) {
                        moveX = x;
                        moveY = y;
                        board.Place(x, y, '_');
                        return true;
                    }
                    board.Place(x, y, '_');
                }
            }
        }
        return false;
	}

    bool TakeCenter(Board& board, int& moveX, int& moveY) {
        if (board.IsCellFree(1, 1)) {
            moveX = 1;
            moveY = 1;
            return true;
        }
        return false;
    }

    void TakeAny(Board& board, int& moveX, int& moveY) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (board.IsCellFree(x, y)) {
                    moveX = x;
                    moveY = y;
                    return;
                }
            }
        }
    }
};