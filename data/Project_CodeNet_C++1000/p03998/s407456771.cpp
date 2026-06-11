#include<iostream>
using namespace std;

int getNextTurn(int currentTurn, string decks[]){
    if(decks[currentTurn].length() == 0){
        return -1;
    }
    int nextTurn = decks[currentTurn][0] - 'a';
    decks[currentTurn] = decks[currentTurn].substr(1);
    return nextTurn;
}

int main(){
    string decks[3];
    for(int i=0; i<3; i++){
        cin >> decks[i];
    }

    int currentTurn = 0;
    while(true){
        int nextTurn = getNextTurn(currentTurn, decks);
        if(nextTurn < 0){
            cout << ((char)('A'+currentTurn)) << '\n';
            break;
        }
        currentTurn = nextTurn;
    }
}
