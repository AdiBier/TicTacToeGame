#pragma once

#include <iostream>
using namespace std;

class InputHandler {
public:
    bool GetMove(int& outX, int& outY) const {
        int choice;
        cin >> choice;

        if (!cin || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(1000, '\n');
            return false;
        }

        choice--;
        outY = choice / 3;
        outX = choice % 3;
        return true;
    }
};