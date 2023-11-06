//
//  tests_rps.cpp
//  rps_game
//
//  Created by Ibrahim Haroon on 11/6/23.
//

#include "tests_rps.hpp"
#include <cassert>
#include <sstream>
#include <iostream>
#include "RPS.hpp"

void test_that_rps_default_constructor_sets_selected_move_correctly(void);
void test_that_rps_constructor_sets_selected_move_sets_correctly_given_string(void);
void test_that_rps_overloaded_ostream_outputs_correct_string(void);
void test_that_rps_overloaded_istream_reads_in_text_correctly(void);
void test_that_computer_move_randomizer_returns_value_within_correct_range(void);
void test_that_play_with_zero_args_returns_correct_outcome(void);
void test_that_play_with_rps_obj_arg_returns_correct_outcome(void);

void driver(void) {
    test_that_rps_default_constructor_sets_selected_move_correctly();
    test_that_rps_constructor_sets_selected_move_sets_correctly_given_string();
    test_that_rps_overloaded_ostream_outputs_correct_string();
    test_that_rps_overloaded_istream_reads_in_text_correctly();
    test_that_computer_move_randomizer_returns_value_within_correct_range();
    
    std::cout << "**\nPassed all tests!**" << std::endl;
}

void test_that_rps_default_constructor_sets_selected_move_correctly(void) {
    // arrange
    RPS test_obj;
    
    // act
    
    // assert
    xassert(test_obj.selected_move() == none, "expected move to be 'none' but got: %s", test_obj.toString());
}

void test_that_rps_constructor_sets_selected_move_sets_correctly_given_string(void) {
    // arrange
    RPS test_obj("rock");
    
    // act
    
    // assert
    xassert(test_obj.selected_move() == rock, "expected selected move to be 'rock' but got %s", test_obj.toString());
}

void test_that_rps_overloaded_ostream_outputs_correct_string(void) {
    // arrange
    RPS test_obj;
    std::stringstream ss;
    std::string output;
    std::string expectedOutput = "current move: none";
    
    // act
    ss << test_obj;
    output = ss.str();
    
    // assert
    xassert(output == expectedOutput, "expected output to be 'none' but got %s", output);
}

void test_that_rps_overloaded_istream_reads_in_text_correctly(void) {
    // arrange
    RPS test_obj;
    std::stringstream ss("none"); // simulate the input of "none"
    
    // act
    ss >> test_obj;
    
    // assert
    xassert(test_obj.selected_move() == none, "expected selected move to be none not %s", test_obj.toString());
}

void test_that_computer_move_randomizer_returns_value_within_correct_range(void) {
    // arrange
    RPS test_obj;
    
    // act
    for (int i = 0; i < 1000; i++) {
        
        // assert
        xassert(test_obj.computer_move() >= 0 && test_obj.computer_move() <= 3, "expected computer move to be in range 0 <= x <= 3");
    }
}

void test_that_play_with_zero_args_returns_correct_outcome(void) {
    // arrange
    
    // act
    
    // assert
}

void test_that_play_with_rps_obj_arg_returns_correct_outcome(void) {
    // arrange
    
    // act
    
    // assert
}
