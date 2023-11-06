//
//  tests_rps.hpp
//  rps_game
//
//  Created by Ibrahim Haroon on 11/6/23.
//

#ifndef tests_rps_hpp
#define tests_rps_hpp

#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

#define xassert(condition, message, ...) \
do { \
if (!(condition)) { \
std::cerr << "Assertion failed: " << message << " at line " << __LINE__ << std::endl; \
throw std::logic_error("Assertion failed: " + std::string(message)); \
} \
} while (false)

void driver(void);
void test_that_rps_default_constructor_sets_selected_move_correctly(void);
void test_that_rps_constructor_sets_selected_move_sets_correctly_given_string(void);
void test_that_rps_overloaded_ostream_outputs_correct_string(void);
void test_that_rps_overloaded_istream_reads_in_text_correctly(void);
void test_that_computer_move_randomizer_returns_value_within_correct_range(void);
void test_that_play_with_zero_args_returns_correct_outcome(void);
void test_that_play_with_rps_obj_arg_returns_correct_outcome(void);

#endif /* tests_rps_hpp */
