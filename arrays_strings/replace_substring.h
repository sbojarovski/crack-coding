//
// Created by stefan on 10/29/18.
//

#ifndef ARRAYS_STRINGS_REPLACE_SUBSTRING_H
#define ARRAYS_STRINGS_REPLACE_SUBSTRING_H

void replace_space_substr(char * input){
    char rep[4] = "%20";
    int sub_size = 3; // it can be determined dynamically
    int i = 0;
    char * end;
    int num_spaces = 0;

    while (input[i]){
        if (input[i] == ' ')
            num_spaces++;
        i++;
        if (input[i])
            end = &*input + i;
    }

    int offset = num_spaces / (sub_size + 1);

    while(i){
        if (input[i] != ' '){
            input[i + offset] = input[i];
        }
        else{
            input[i] = '%';
            input[i + 1] = '2';
            input[i + 2] = '0';
        }
        i--;
    }
}

#endif //ARRAYS_STRINGS_REPLACE_SUBSTRING_H
