//
// Created by stefan on 10/29/18.
//

#ifndef ARRAYS_STRINGS_REPLACE_SUBSTRING_H
#define ARRAYS_STRINGS_REPLACE_SUBSTRING_H

#include <vector>
#include <iostream>
#include <cstring>

void replace_space_substr(char * input){
    int sub_size = 3; // it can be determined dynamically
    int i = 0;
    int num_spaces = 0;

    while (input[i]){
        if (input[i] == ' ')
            num_spaces++;
        i++;
    }
    if (!i)
        return;
    int real_spaces = num_spaces / sub_size;
    int padding_size = real_spaces * (sub_size - 1);
    if (num_spaces - real_spaces != padding_size)
        return;
    int offset = real_spaces * (sub_size - 1);

    i -= padding_size + 1;

    while(i >= 0){
        input[i + offset] = input[i];
        if (input[i] == ' '){
            input[i + offset] = '0';
            input[i + offset - 1] = '2';
            input[i + offset - 2] = '%';
            real_spaces--;
            offset = real_spaces * (sub_size - 1);
        }
        i--;
    }
}

void test_replace_substring(){
    std::vector<std::string> inputs = {
            "ab c  def      ",
            "   ",
            "",
            " b  ",
            "  b    ",
            "a b  c   d    e                    ",
            "    a   b  c d                    "
    };
    for (auto & s : inputs) {
        char *c = new char[s.size()];
        std::strcpy(c, s.c_str());
        replace_space_substr(c);
        std::cout << c << std::endl;
        delete [] c;
    }
}

#endif //ARRAYS_STRINGS_REPLACE_SUBSTRING_H
