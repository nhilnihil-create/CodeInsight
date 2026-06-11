#include <bits/stdc++.h>

using namespace std;

void solve() {
    map<char, string> S;
    cin >> S['a'] >> S['b'] >> S['c'];
    char player, next_player;
    player = 'a';
    while(1)
    {
        if (S[player].length() == 0)
        {
            cout << (char)toupper(player) << endl;
            return;
        }
        
        next_player = S[player][0];
        S[player].erase(0,1);
        player = next_player;
        
    }
}

int main() {
    solve();
    return 0;
}