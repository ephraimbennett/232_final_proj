#include "GamePiece.h"
#include <algorithm>


GamePiece::GamePiece(std::string n, std::string t, GameState* s) {
    name = n;
    type = t;
    state = s;
    UpdateState();
}

GamePiece::~GamePiece() {
    state->RemovePiece(name, type);
}

void GamePiece::UpdateState() {
    state->AddPiece(name, type);
}

GamePiece::GamePiece(const GamePiece & other) {
    name = other.GetPlayer();
    type = other.GetType();
    state = other.state;
    UpdateState();
}

GamePiece& GamePiece::operator=(const GamePiece & other) {
    state->RemovePiece(name, type);
    name = other.GetPlayer();
    type = other.GetType();
    state = other.state;
    UpdateState();
    return *this;
}

std::string GamePiece::GetPlayer() const {
    return name;
}

std::string GamePiece::GetType() const {
    return type;
}

int GamePiece::GetPower() const {
    if (type == "Warrior") {
        return 5;
    } else if (type == "Scout") {
        return 1;
    } else if (type == "Wizard") {
        return state->NumPieces(name, type);
    }
    return 0;
}

int GamePiece::OtherWizards() const {
    std::vector<std::string> players = state->GetPlayers();
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i) == name) {
            players.erase(players.begin() + i);
        }
    }
    int wizards = 0;
    for (auto p : players) {
        wizards += state->NumPieces(p, "Wizard");
    }
    return wizards;
}

int GamePiece::GetSpeed() const {
    if (type == "Warrior") {
        return 2;
    } else if (type == "Scout") {
        return 8;
    } else if (type == "Wizard") {
        int speed = 12 - OtherWizards();
        if (speed < 1) {
            return 1;
        }
        return speed;
    }
    return 0;
}

bool operator<(const GamePiece & g1, const GamePiece & g2) {
    if (g1.GetPower() < g2.GetPower()) {
        return true;
    } else if (g1.GetPower() == g2.GetPower()) {
        if (g1.GetSpeed() < g2.GetSpeed()) {
            return true;
        }
    }
    return false; 
}

bool operator>(const GamePiece & g1, const GamePiece & g2) {
    return operator<(g2, g1);
}

bool operator<=(const GamePiece & g1, const GamePiece & g2) {
    return !(operator>(g1, g2));
}

bool operator>=(const GamePiece & g1, const GamePiece & g2) {
    return !(operator<(g1,  g2));
}

bool operator==(const GamePiece & g1, const GamePiece & g2) {
    if (g1.GetPower() == g2.GetPower()) {
        if (g1.GetSpeed() == g2.GetSpeed()) {
            return true;
        }
    }
    return false;
}

bool operator!=(const GamePiece & g1, const GamePiece & g2) {
    return !(operator==(g1, g2));
}

std::ostream& operator<< (std::ostream & os, const GamePiece & gp) {
    os << "(" << gp.name << "," << gp.type << "," << gp.GetPower() << "," << gp.GetSpeed() << ")";
    return os;
}