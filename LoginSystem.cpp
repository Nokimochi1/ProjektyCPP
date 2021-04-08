#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string username;
string password;
int userChoice;
string checkLetter;
vector <string> data;

void userMessages(int a){
    if (a == 1){
        cout<< "1. Login" << endl;
        cout<< "2. Register" << endl;
        cin  >> userChoice;
    }
    else if (a == 2){
        cout<< "Enter your username: ";
        cin >> username; 
        cout << "Enter your password: ";
        cin >> password;
    }
    else if (a == 3){
        cout << "Do you want to quit? (Y/n)" << endl;
        cin >> checkLetter;
    }
    else if (a == 4){
        cout << "You logged in succesfully!" << endl;
    }
    else if (a == 5){
        cout << "This account doesnt exist, sorry" << endl;
    }


}

void fileToList(){
    ifstream in("database.txt");
    string element;
    while (in >> element){
        data.push_back(element);
    }
}

void userRegistration(string username, string password){
    ofstream data("database.txt", ios_base::app);
    data << username + ":" + password;
    data << "\n";
    data.close();
}

bool userLogin(string username, string password){
    fileToList();
    string lookfor = username + ":" + password;
    if (find(data.begin(), data.end(), lookfor) != data.end()){
        return true;

    }
    return false;
}


int main(){
    userMessages(1);
    
    
    if (userChoice == 1){
        userMessages(2);
        if (userLogin(username, password)){
            userMessages(4);
            userMessages(3);
            if (checkLetter == "Y") return 0;
            if (checkLetter == "n") main();
        }
        else{
            userMessages(5);
            userMessages(3);
            if (checkLetter == "Y") return 0;
            if (checkLetter == "n") main();
        }
    }
    else if (userChoice == 2){
        userMessages(2);
        userRegistration(username, password);
        userMessages(3);
        if (checkLetter == "Y") return 0;
        if (checkLetter == "n") main();

    }



}