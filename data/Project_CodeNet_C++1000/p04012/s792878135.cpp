#include<bits/stdc++.h>
using namespace std;

int main() {
    string W;
    cin >> W;
    map<char, int> words;

    for(auto WI : W) {
        words[WI]++;
    }

    bool btf = true;
    for(auto WI : W) {
        if(words[WI] % 2 == 1) {
            btf = false;
            break;
        }
    }

    if(btf) cout << "Yes" << endl;
    else cout << "No" << endl;
}