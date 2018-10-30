//
// Created by stefan on 10/29/18.
//

#include <iostream>
#include "str_all_unqiue.h"
#include "replace_substring.h"

int main(int argc, char ** argv){
//    test_unique_checks();
    char input[10] = "abc def  ";
    replace_space_substr(input);
    std::cout << input << std::endl;
    return 0;
}