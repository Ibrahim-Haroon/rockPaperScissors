//
//  RPS.hpp
//  rps_game
//
//  Created by Ibrahim Haroon on 11/6/23.
//

#ifndef RPS_hpp
#define RPS_hpp

#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

enum {none, rock, paper, scissor};

class RPS {
public:
    RPS();
    RPS(std::string move);
    friend std::istream& operator>>(std::istream& is, RPS& obj);
    friend std::ostream& operator<<(std::ostream& os, RPS& obj);
    int selected_move(void);
    int computer_move(void);
    std::string toString(void);
private:
    std::unordered_map<std::string, int> rps_map = {{"none", 0}, {"rock", 1}, {"paper", 2}, {"scissor", 3}};
    // only need 2 bits: 00, 01, 10, 11
    unsigned int _selected_move : 2;
    int computer_move_randomizer(void);
};

bool play(void);
bool play(RPS player);

#endif /* RPS_hpp */
