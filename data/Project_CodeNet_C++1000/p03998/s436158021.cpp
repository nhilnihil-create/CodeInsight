#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> deck;
    int i;
    for(i=0; i<3; i++){
        string s;
        getline(cin, s);
        deck.push_back(s);
    }

    string t = "abc";

    bool gameWon = false;
    i =0;
    size_t j[3] = {0};
    int winner;

    while(!gameWon){
        if(j[i] == deck[i].size()){
            gameWon = true;
            winner = i;
            break;
        }

        if(deck[i][j[i]] == t[0]){
            j[i]++;
            i = 0;
        } else if (deck[i][j[i]] == t[1]) {
            j[i]++;
            i = 1;
        } else {
            j[i]++;
            i = 2;
        }
    }

    if(winner == 0){
        cout << "A" <<endl;
    }else if(winner == 1){
        cout << "B" <<endl;
    }else {
        cout << "C"<< endl;
    }
}
