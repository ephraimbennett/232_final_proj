#pragma once

#include "GameState.h"
#include <string>
#include <iostream>
#include <sstream>

class GamePiece {
    private :
        std::string name;
        std::string type;
        int OtherWizards() const;
    public :
        GameState * state;

        GamePiece(std::string n, std::string t, GameState* s);
        GamePiece(const GamePiece & other);
        ~GamePiece();
        GamePiece& operator=(const GamePiece & other);

        void UpdateState();

        std::string GetPlayer() const;
        std::string GetType() const;
        int GetPower() const;
        int GetSpeed() const;

        friend bool operator< (const GamePiece & g1, const GamePiece & g2);
        friend bool operator> (const GamePiece & g1, const GamePiece & g2);
        friend bool operator<= (const GamePiece & g1, const GamePiece & g2);
        friend bool operator>= (const GamePiece & g1, const GamePiece & g2);
        friend bool operator== (const GamePiece & g1, const GamePiece & g2);
        friend bool operator!= (const GamePiece & g1, const GamePiece & g2);
        
        friend std::ostream& operator<< (std::ostream & os, const GamePiece & gp);
};
