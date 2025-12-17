#pragma once
#include <iostream>

const int BOARD_SIZE = 3;
const char EMPTYY_CHAR = '_';

class Board {
public:
    Board() {
        for (int y = 0; y < BOARD_SIZE; y++)
            for (int x = 0; x < BOARD_SIZE; x++)
                cells[y][x] = EMPTYY_CHAR;
    }

    bool IsCellFree(int x, int y) const {
        return cells[y][x] == EMPTYY_CHAR;
    }

    void Place(int x, int y, char symbol) {
        cells[y][x] = symbol;
    }

    char GetCell(int x, int y) const {
        return cells[y][x];
    }

    bool CheckWin(char symbol) const {
        // wiersze i kolumny
        for (int i = 0; i < BOARD_SIZE; i++) {
            if ((cells[i][0] == symbol && cells[i][1] == symbol && cells[i][2] == symbol) ||
                (cells[0][i] == symbol && cells[1][i] == symbol && cells[2][i] == symbol))
                return true;
        }

        // przek¹tne
        if ((cells[0][0] == symbol && cells[1][1] == symbol && cells[2][2] == symbol) ||
            (cells[0][2] == symbol && cells[1][1] == symbol && cells[2][0] == symbol))
            return true;

        return false;
    }

    bool IsDraw() const {
        for (int y = 0; y < BOARD_SIZE; y++)
            for (int x = 0; x < BOARD_SIZE; x++)
                if (cells[y][x] == EMPTYY_CHAR)
                    return false;
        return true;
    }

private:
    char cells[BOARD_SIZE][BOARD_SIZE];
};
