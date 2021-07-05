/*
 * main.cpp
 *
 *  Created on: Jul 5, 2021
 *      Author: d-w-h
 */

#include <stdio.h>
#include <limits.h>
#include <string>

int my_atoi(std::string s) {
    int size_string = s.length();
    long long int int_max = INT_MAX;
    long long int int_min = INT_MIN;

    int min_char = '-';
    int plus_char = '+';
    int min_int_range = '0';
    int max_int_range = '9';
    int white_space_char = ' ';

    char* s_ptr = new char[size_string];
    for(int i = 0; i < size_string; ++i) {
        s_ptr[i] = s[i];
    }

    //Loop through front of string to check if input is valid
    bool valid_input_bool = false;
    bool validity_of_input_is_known = false;
    int index_track = 0;
    while(!validity_of_input_is_known && index_track < size_string) {
        int the_char_loc = s[index_track];
        if(the_char_loc == white_space_char) { index_track++; }
        else {
            valid_input_bool = (the_char_loc >= min_int_range && the_char_loc <= max_int_range);
            if(valid_input_bool) { valid_input_bool = true; validity_of_input_is_known = true; }
            else if(the_char_loc == min_char || the_char_loc == plus_char) {
                int next_char = s[index_track+1];
                bool next_char_valid = (next_char >= min_int_range && next_char <= max_int_range);
                if(next_char_valid) { valid_input_bool = true; validity_of_input_is_known = true; }
                else { valid_input_bool = false; validity_of_input_is_known = true; }
            }
            else { valid_input_bool = false; validity_of_input_is_known = true; }
        }
    }

    long long int x;
    int result = 0;
    if(valid_input_bool && size_string > 0) {
        sscanf(s_ptr, "%I64d", &x); //Format specifier may need to be changed to %lld for non-windows systems

        if(x > int_max) { result = INT_MAX; };
        if(x < int_min) { result = INT_MIN; };
        if(x <= int_max && x >= int_min) { result = x; }
    }
    return result;
}

int main(int argc, char* argv[]) {

    std::string s = " -314";

    int result = my_atoi(s);

    printf("result: %d", result);

    return 0;
}
