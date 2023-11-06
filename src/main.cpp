//
//  main.cpp
//  rps_game
//
//  Created by Ibrahim Haroon on 11/6/23.
//

#include "RPS.hpp"

int main(int argc, const char * argv[]) {
    play(RPS("rock")) ? std::cout << "Won" << std::endl : std::cout << "Lost" << std::endl;
    
    return 0;
}
