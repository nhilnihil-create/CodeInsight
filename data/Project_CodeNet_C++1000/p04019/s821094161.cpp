#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    map<char, int> hougaku;
    hougaku['N'] = 0;
    hougaku['W'] = 0;
    hougaku['S'] = 0;
    hougaku['E'] = 0;
    for (int i = 0; i < S.size(); i++)
    {
        hougaku[S[i]]++;
    }
    if (hougaku['N'] * hougaku['S'] == 0 && hougaku['N'] + hougaku['S'] != 0)
    {
        cout << "No" << endl;
        return;
    }
    if (hougaku['W'] * hougaku['E'] == 0 && hougaku['W'] + hougaku['E'] != 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    
}

int main() {
    solve();
    return 0;
}