//
// Created by stefan on 10/29/18.
//

#ifndef CRACK_CODING_STR_ALL_UNQIUE_H
#define CRACK_CODING_STR_ALL_UNQIUE_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <chrono>
#include <unordered_set>

/*
 * Check if all the chars in a string are unique, using a set
 * */

bool all_unique_set(const std::string & input){
    std::set<char> appeared;
    for (auto & c : input){
        if (!appeared.emplace(c).second)
            return false;
    }
    return true;
}

/*
 *  Check if all the chars in a string are unique, with using a simple bool array
 *  Complexity: time -- linear O(n), space -- about 100 size vector of bools
 * */
bool all_unique_boolvec(const std::string & input){
    const unsigned int NCHARS = (int)'z' - (int)'0';
    const unsigned int OFFSET = (int)'0';
    bool appeared[NCHARS] = {false};
    for(auto & c : input){
        if (appeared[c - OFFSET])
            return false;
        appeared[c - OFFSET] = true;
    }
    return true;
}

/*
 * Check if all the chars in a string are uniqe, without using any additional data structure
 * Complexity O(n^2)
 * */
bool all_unique(const std::string & input){
    for (auto i = input.begin(); i != input.end(); ++i){
        for (auto j = std::next(i); j != input.end(); ++j){
            if (*i == *j)
                return false;
        }
    }
    return true;
}

void test_unique_checks(){
    std::vector<std::string> inputStrings = {
            "abcde",
            "",
            "abbcde",
            "0123abcd",
            "0123456789abcdefghjiklmnopqrstuvwxyz0"
    };
    for(auto & s : inputStrings){
        std::cout << s << ":" << std::endl;
        auto start = std::chrono::system_clock::now();
        bool res = all_unique(s);
        auto end = std::chrono::system_clock::now();
        std::cout << "no structure:\t" << res << "\t" << (end - start).count() << std::endl;

        start = std::chrono::system_clock::now();
        res = all_unique_boolvec(s);
        end = std::chrono::system_clock::now();
        std::cout << "boolean vector:\t" << res << "\t" << (end - start).count() << std::endl;

        start = std::chrono::system_clock::now();
        res = all_unique_set(s);
        end = std::chrono::system_clock::now();
        std::cout << "ordered set:\t" << res << "\t" << (end - start).count() << std::endl;
        std::cout << std::endl;
    }
}
#endif //CRACK_CODING_STR_ALL_UNQIUE_H
