#pragma once

enum class PlayerType {
    Human,
    AI
};

class Player {
public:
	Player(char symbol, PlayerType playerType) : symbol(symbol), type(playerType){}
    
    char GetSymbol() const {
		return symbol;
    }
    PlayerType GetType() const {
        return type;
	}
    void SetType(PlayerType playerType) {
        type = playerType;
	}

private:
    char symbol;
    PlayerType type;
};