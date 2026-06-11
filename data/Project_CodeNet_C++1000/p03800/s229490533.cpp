#include <bits/stdc++.h>
using namespace std;

int state[100005];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; string s;

    cin >> n >> s;

    for(int i = 0; i < 2; ++i){
        for(int yikes = 0; yikes < 2; ++yikes){
            for(int j = 0; j < n; ++j)
                state[j] = -1;
            state[0] = i;
            if((s[0] == 'o') ^ i){
                state[1] = state[n - 1] = yikes;
            } else {
                state[1] = yikes; state[n - 1] = 1 - yikes;
            }
            bool bad = false;
            for(int pos = 1; pos < n; ++pos){
                if((s[pos] == 'o') ^ (state[pos] == 1)){
                    if(state[(pos + 1) % n] != -1 && state[pos - 1] != state[(pos + 1) % n])
                        bad = true;
                    state[(pos + 1) % n] = state[pos - 1];
                } else {
                    if(state[(pos + 1) % n] != -1 && state[pos - 1] == state[(pos + 1) % n])
                        bad = true;
                    state[(pos + 1) % n] = 1 - state[pos - 1];
                }
            }
            if(bad) continue;
            for(int pos = 0; pos < n; ++pos)
                cout << (state[pos] == 0 ? "S" : "W");
            cout << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;

}
