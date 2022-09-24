#include "filesCreation.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void createFiles(string path){
    cout << "Creating game files." << endl;
    ofstream file;
    file.open(path + "\\userProfile.txt"); file.close();
    file.open(path + "\\inventory.txt"); file.close();
    file.open(path + "\\stats.txt"); file.close();
    file.open(path + "\\teleport_points.txt"); file.close();
    file.open(path + "\\quests.txt"); file.close();
}