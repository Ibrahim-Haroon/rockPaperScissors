//
//  RPS.cpp
//  rps_game
//
//  Created by Ibrahim Haroon on 11/6/23.
//

#include "RPS.hpp"

RPS::RPS() {
    _selected_move = none;
}

RPS::RPS(std::string move) {
    try {
        std::unordered_map<std::string, int>::iterator it = rps_map.find(move);
        if (it != rps_map.end()) {
            _selected_move = it ->second;
        }
        else {
            throw std::invalid_argument("Invalid move: " + move);
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        throw;
    }
}

std::istream& operator>>(std::istream& is, RPS& obj) {
    std::string input = "";
    int selected_move;
    do {
        std::cout << "Please enter a move (rock, paper, scissor): ";
        is >> input;
        selected_move = obj.rps_map.find(input) != obj.rps_map.end() ? obj.rps_map[input] : none;
    }
    while (selected_move < 0 || selected_move > 3);
    
    obj._selected_move = selected_move;
    return is;
}

std::ostream& operator<<(std::ostream& os, RPS& obj) {
    return os << "current move: "<< obj.toString();
}

int RPS::selected_move(void) {
    return -1;
}

int RPS::computer_move(void) {
    return computer_move_randomizer();
}

std::string RPS::toString(void) {
    const std::string moves[] = {"none", "rock", "paper", "scissor"};
    std::string move_as_string;
    try {
        move_as_string = moves[_selected_move];
    }
    catch (std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        throw;
    }
    
    return move_as_string;
}

int RPS::computer_move_randomizer(void) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(0, 3);
    
    return distribution(generator);
}

bool play(void) {
    RPS player;
    std::cin >> player;
    int computer = player.computer_move();
    int user = player.selected_move();
    
    if (user == rock && computer == scissor) {
        return true;
    }
    if (user == paper && computer == rock) {
        return true;
    }
    if (user == scissor && computer == paper) {
        return true;
    }
    
    return false;
}

bool play(RPS player) {
    int computer = player.computer_move();
    int user = player.selected_move();
    
    if (user == rock && computer == scissor) {
        return true;
    }
    if (user == paper && computer == rock) {
        return true;
    }
    if (user == scissor && computer == paper) {
        return true;
    }
    
    return false;
}
