#include <bits/stdc++.h>
using namespace std;
bool canPlay =  true;
char itemsIn[9]  = {'-','-','-','-','-','-','-','-','-'};
bool allFilled = false;
bool canPlaceHere(int n){
    if (itemsIn[n - 1] != '-'){
        return false;
    }
    return true;
}
bool isGameOver(){
    bool doHaveSpace = false;
    for (int i = 0; i < 9; i++){
        if (itemsIn[i] == '-'){
            doHaveSpace = true;
        }
    }
    if (itemsIn[0] != '-' && itemsIn[0] == itemsIn[1] && itemsIn[0] == itemsIn[2]){
        return true;
    }else if (itemsIn[0] != '-' && itemsIn[0] == itemsIn[3] && itemsIn[0] == itemsIn[6]){
        return true;
    }else if (itemsIn[6] != '-' && itemsIn[6] == itemsIn[7] && itemsIn[6] == itemsIn[8]){
        return true;
    }else if (itemsIn[2] != '-' && itemsIn[2] == itemsIn[5] && itemsIn[2] ==  itemsIn[8]){
        return true;
    }else if (itemsIn[0] != '-' && itemsIn[0] == itemsIn[4] && itemsIn[0] == itemsIn[8]){
        return true;
    }else if (itemsIn[2] != '-' && itemsIn[2] == itemsIn[4] && itemsIn[2] == itemsIn[6]){
        return true;
    }else if (doHaveSpace == false){
        allFilled = true;
        return true;
    }
    return false;
}

void printBoardNow(int n, int g){
    if (g == 1){
        itemsIn[n - 1] = 'X';
    }
    if (g == 2){
        itemsIn[n - 1] = 'O';
    }
    cout << "      |     |     " << endl;
    cout << "   "<<itemsIn[0]<<"  |  "<<itemsIn[1]<<"  |  "<<itemsIn[2]<<"  " << endl;
    cout << " _____|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   "<<itemsIn[3]<<"  |  "<<itemsIn[4]<<"  |  "<<itemsIn[5]<<"  " << endl;
    cout << " _____|_____|_____" << endl;
    cout << "      |     |     " << endl;
    cout << "   "<<itemsIn[6]<<"  |  "<<itemsIn[7]<<"  |  "<<itemsIn[8]<<"  " << endl;
    cout << "      |     |    " << endl;

}
void getInput(int place, int ID){
    if (ID == 1){
        cout << "Where do you want to place a Cross? (1-9)" << endl;
        cin >> place;
        if (canPlaceHere(place)){
            printBoardNow(place, 1);
            if (isGameOver()){
                if (allFilled){
                    canPlay = false;
                    cout << "Draw" << endl;
                }else{
                    cout << "Cross won" << endl;
                    canPlay = false;
                }
            }   
        }else{
            cout << "Sorry you can't place cross here" << endl;
            getInput(place, 1);
        }
    }else{
        cout << "Where do you want to place a Circle? (1-9)" << endl;
        cin >> place;
        if (canPlaceHere(place)){
            printBoardNow(place, 2);
            if (isGameOver()){
                cout << "Circle Won" << endl;
                canPlay = false;
            }
        }else{
            cout << "Sorry you can't place circle here" << endl;
            getInput(place, 2);
        }
    }
    
}
void twoPlayersMode(){
    int place;
    while (canPlay){
        getInput(place, 1);
        if (allFilled == true){
            break;
        }else if (canPlay == false){
            break;
        }
        getInput(place, 2);
    }
}
void AIMode(){

}
int main(){
    int n= 0;
    int checkChoice;
    int numOfRounds = 1;
    cout << "1. Play With AI | 2. Two Players Mode ";
    cin >> checkChoice;
    if (checkChoice == 1){
        AIMode();
    }else if (checkChoice == 2){
        twoPlayersMode();
    }
}