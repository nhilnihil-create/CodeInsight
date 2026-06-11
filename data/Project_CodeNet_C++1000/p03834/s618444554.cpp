#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N = 20;
    string word(N, 'a');
    cin >> word;

    rep (i,word.size()) {
        if (word[i] == ',') word[i] = ' ';
    }

    string greeting;
    rep (i,word.size()) {
        greeting += word[i];
    }

    cout << greeting << endl;
    
    return 0;
}