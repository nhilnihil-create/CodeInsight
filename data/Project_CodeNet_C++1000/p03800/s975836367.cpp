#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<string> patterns{"SS", "SW", "WS", "WW"};
    for (string &pat : patterns) {
        for (int i = 1; i < n-1; i++) {
            if ((s[i] == 'o' && pat[i] == 'S') || (s[i] == 'x' && pat[i] == 'W')) {
                pat += pat[i - 1];
            } else {
                pat += (pat[i - 1] == 'S' ? 'W' : 'S');
            }
        }
        if (s[n-1] == 'o') {
            if (!((pat[n-1] == 'S' && pat[n-2] == pat[0]) || (pat[n-1] == 'W' && pat[n-2] != pat[0])))
                continue;
        } else {
            if (!((pat[n-1] == 'S' && pat[n-2] != pat[0]) || (pat[n-1] == 'W' && pat[n-2] == pat[0])))
                continue;
        }
        if (s[0] == 'o') {
            if (!((pat[0] == 'S' && pat[n-1] == pat[1]) || (pat[0] == 'W' && pat[n-1] != pat[1])))
                continue;
        } else {
            if (!((pat[0] == 'S' && pat[n-1] != pat[1]) || (pat[0] == 'W' && pat[n-1] == pat[1])))
                continue;
        }
        cout << pat << endl;
        return 0;    
    }
    puts("-1");
}