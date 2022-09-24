#include "profileCreation.hpp"
#include "../../Utils/strings/ustrings.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

void createProfile(string path){
    string username, confirmName, confirmClass;

    cout << "What's your username ?" << endl;
    cin >> username;
    cout << "Your username has been set to " + username + ". Is that right ? (yes/no)" << endl;
    cin >> confirmName;
    ustrings::toLowerCase(confirmName);
    while (confirmName != "yes"){
        cout << "What's your username ?" << endl;
        cin >> username;
        cout << "Your username has been set to " + username + ". Is that right ? (yes/no)" << endl;
        cin >> confirmName;
    }
    profileCreation::setUsername(path, username);
    cout << "Good, now you will have to choose a class" << endl;
    cout << "Here is the selection : " << endl;
    profileCreation::chooseAndSetClass(path);
}

void setUsername(string path, string username){
    ofstream file;
    file.open(path + "\\userProfile.txt");
    file << "Username: " + username << endl;
    file.close();
}

void chooseAndSetClass(string path){
    cout << "Name           Health   Mana   Strength   Dexterity           Description" << endl;
    cout << endl;
    cout << "Barabarian       30      10       40         20         More melee damage, no range" << endl;
    cout << "Archer           15      25       20         30         More ranged damages, no melee, avoid easily" << endl;
    cout << "Mage             20      50       10         25         Mixed between the two lasts, lot of magical attacks" << endl;
    cout << endl;
    cout << "         These stats are the default ones, can be upgraded" << endl;
    cout << endl;
    cout << "So which class do you choose ? (Barbarian/Archer/Mage)" << endl;
    string classe;
    cin >> classe;
    ofstream file;
    file.open(path + "\\userProfile.txt", std::ios_base::app); 
    ustrings::toLowerCase(classe);
    while(classe != "barbarian" && classe != "archer" && classe != "mage"){
        cout << "This class doesn't exist." << endl;
        cout << "Select a class. (Barbarian/Archer/Mage)" << endl;
        string classe;
        cin >> classe;
        ustrings::toLowerCase(classe);
    }
    if(classe == "barbarian") {
        classe = "Barbarian";
    } else if(classe == "archer") {
        classe = "Archer";
    } else if(classe == "mage"){
        classe = "Mage";
    }
    file << "Class: " + classe << endl;
    file.close();
    setStats(classe, path);
}

void setStats(string classe, string path){
    ofstream file;
    cout << classe;
    file.open(path + "\\stats.txt", std::ios_base::app);
    
    if(classe == "barbarian"){
        file << "Health: 30" << endl;
        file << "Mana: 10" << endl;
        file << "Strength: 40" << endl;
        file << "Dexterity: 20" << endl;
    } else if(classe == "archer"){
        file << "Health: 15" << endl;
        file << "Mana: 25" << endl;
        file << "Strength: 20" << endl;
        file << "Dexterity: 30" << endl;
    } else if(classe == "mage"){
        file << "Health: 20" << endl;
        file << "Mana: 50" << endl;
        file << "Strength: 10" << endl;
        file << "Dexterity: 25" << endl;
    }
    file << "Quests completed: 0" << endl;
    file << "Won fights: 0" << endl;
    file << "Village visited: 0" << endl;
    file << "Teleport points unlocked: 0" << endl;
    file.close();
}