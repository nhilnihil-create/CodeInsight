#include <bits/stdc++.h>
using namespace std;

int main() {
    string w; cin >> w;
    map<char, int> ch;
    for (int i = 0; i < (int)w.size(); i++) ch[w[i]]++;

    for (int i = 0; i < (int)w.size(); i++) {
        if (ch[w[i]] % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}