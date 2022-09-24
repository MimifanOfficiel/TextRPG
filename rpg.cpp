#include <iostream>
#include <string>
#include <filesystem>
#include "./browseFiles/browseFiles.hpp"
#include "./gameCreation/profileCreation/profileCreation.hpp"
#include "./gameCreation/filesCreation/filesCreation.hpp"
#include "./Utils/strings/ustrings.hpp"

namespace fs = std::filesystem;
using namespace std;

string path;

void PrepareGame(){
    string effect = "new";
    cout << "What do you wanna do ? New game or load game ? (new / load)" << endl;
    cin >> effect;
    std::for_each(effect.begin(), effect.end(), [](char & c) {
        c = ::tolower(c);
    });
    path = browseFiles::BrowseFolder("");
    fs::create_directory(path + "\\gameFiles");
    path = path + "\\gameFiles";
    cout << path;
    
    if(effect == "new"){
        filesCreation::createFiles(path);
    } else if(effect == "load"){
        
    }
    profileCreation::createProfile(path);
}



main(){
    PrepareGame();
    //return EXIT_SUCCESS;
}