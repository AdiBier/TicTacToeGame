#pragma once
#include "Board.h"
#include "Player.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "AIPlayer.h"

class Game {
public:
    Game()
        : playerX('X', PlayerType::Human), playerO('O', PlayerType::AI), 
        currentPlayer(&playerX), 
        isRunning(true),
        moveX(-1), 
        moveY(-1) {
    }

    void Run() {
		ChooseMode();
        while (isRunning) {
            Render();
            GetInput();
            Update();
        }
        Render();
        Shutdown();
    }

private:
    void Render() {
        system("cls");
        renderer.DrawBoard(board);
        if (isRunning)
            renderer.DrawTurn(currentPlayer->GetSymbol());
    }

    void GetInput() {
        if (currentPlayer->GetType() == PlayerType::Human) {
			input.GetMove(moveX, moveY);
        }
        else { 
            ai.MakeAIMove(board, moveX, moveY, currentPlayer->GetSymbol(),
                (currentPlayer == &playerX ? playerO.GetSymbol() : playerX.GetSymbol()));
        }
    }

    void Update() {
        if (moveX == -1 || moveY == -1) return;
        if (!board.IsCellFree(moveX, moveY)) {
            moveX = moveY = -1;
            return;
        }

        board.Place(moveX, moveY, currentPlayer->GetSymbol());

        if (board.CheckWin(currentPlayer->GetSymbol())) {
            winner = currentPlayer->GetSymbol();
            isRunning = false;
            return;
        }

        if (board.IsDraw()) {
            winner = EMPTYY_CHAR;
            isRunning = false;
            return;
        }

        currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
        moveX = moveY = -1;
    }

    void Shutdown() {
        renderer.DrawResult(winner);
    }

    void ChooseMode() {
        char choice;
        std::cout << "Choose game mode:\n";
        std::cout << "1. Player vs Player\n";
        std::cout << "2. Player vs AI\n";
        std::cin >> choice;

        if (choice == '1') {
            playerX.SetType(PlayerType::Human);
            playerO.SetType(PlayerType::Human);
        }
        else {
            playerX.SetType(PlayerType::Human);
            playerO.SetType(PlayerType::AI);
        }
        currentPlayer = &playerX;
    }

private:
    Board board;
    Player playerX;
    Player playerO;
    Player* currentPlayer;
    Renderer renderer;
    InputHandler input;
    AIPlayer ai;

    bool isRunning;
    int moveX, moveY;
    char winner = EMPTYY_CHAR;
};
