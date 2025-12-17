#pragma once
#include "Board.h"
#include <iostream>

using namespace std;

class Renderer {
public:
    void DrawBoard(const Board& board) const {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                char c = board.GetCell(x, y);
                if (c == EMPTYY_CHAR)
                    cout << " " << (y * 3 + x + 1) << " ";
                else
                    cout << " " << c << " ";

                if (x < 2) cout << "|";
            }
            if (y < 2) cout << "\n-----------\n";
        }
        cout << "\n\n";
    }

    void DrawTurn(char playerSymbol) const {
        cout << "Move player " << playerSymbol << endl;
        cout << "Choose position (1-9): ";
    }

    void DrawResult(char winner) const {
        if (winner == EMPTYY_CHAR)
            cout << "Draw!" << endl;
        else
            cout << "Player " << winner << " won!" << endl;
    }
};