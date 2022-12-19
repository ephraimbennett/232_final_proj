#pragma once
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

class GameState {
    private :
        std::vector<std::pair<std::string, std::string>> board;
    public :
        
        GameState() = default;

        void AddPiece(std::string player, std::string type);
        void RemovePiece(std::string player, std::string type);

        int NumPieces();
        int NumPieces(std::string player_name);
        int NumPieces(std::string player_name, std::string piece_type);
        std::vector<std::string> GetPlayers();
};