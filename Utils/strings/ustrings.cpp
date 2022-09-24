#include "ustrings.hpp"
#include <iostream>
#include <string>
#include <filesystem>

void toLowerCase(std::string text){
    std::for_each(text.begin(), text.end(), [](char & c) {
        c = ::tolower(c);
    });
}