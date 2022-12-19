#include "GameState.h"

void GameState::AddPiece(std::string player, std::string type) {
    board.push_back(std::pair<std::string, std::string>(player, type));
}

void GameState::RemovePiece(std::string player, std::string type) {
    for (int i = 0; i < board.size(); i++) {
        if (board.at(i).first == player && board.at(i).second == type) {
            board.erase(board.begin() + i);
            break;
        }
    }
}

int GameState::NumPieces() {
    return board.size();
}

int GameState::NumPieces(std::string player_name) {
    int res = 0;
    for (std::pair<std::string, std::string> p : board) {
        if (p.first == player_name) {
            res++;
        }
    }
    return res;
}
int GameState::NumPieces(std::string player_name, std::string piece_type) {
    int res = 0;
    for (std::pair<std::string, std::string> p : board) {
        if (p.first == player_name && p.second == piece_type) {
            res++;
        }
    }
    return res;
}

std::vector<std::string> GameState::GetPlayers() {
    std::vector<std::string> res;
    for (auto p : board) {
        if (std::find(res.begin(), res.end(), p.first) == res.end()) {
            res.push_back(p.first);
        }
    }
    return res;
}