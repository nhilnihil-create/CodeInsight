#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];
    int player, next_player;
    player = 0;
    while(1)
    {
        if (S[player].length() == 0)
        {
            if (player == 0)
            {
                cout << "A" << endl;
            }
            else if (player == 1)
            {
                cout << "B" << endl;
            }
            else
            {
                cout << "C" << endl;
            }
            return;
        }
        
        if(S[player][0] == 'a')
        {
            next_player = 0;
        }
        else if (S[player][0] == 'b')
        {
            next_player = 1;
        }
        else
        {
            next_player = 2;
        }
        S[player].erase(0,1);
        player = next_player;
        
    }
}

int main() {
    solve();
    return 0;
}