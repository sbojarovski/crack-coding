//
// Created by stefan on 10/29/18.
//

#ifndef ARRAYS_STRINGS_REPLACE_SUBSTRING_H
#define ARRAYS_STRINGS_REPLACE_SUBSTRING_H

void replace_space_substr(char * input, const char * substr){
    char * c = &*input;
    unsigned int offset = 3;
    unsigned int rep = 1;
    while(*c){
        if (*c == ' '){
            char * i = c;
            while(*i == ' ') {
                i++;
                rep++;
            }
        }

        c++;
    }
}

#endif //ARRAYS_STRINGS_REPLACE_SUBSTRING_H
