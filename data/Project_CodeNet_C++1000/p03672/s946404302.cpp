#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >>s;
    int at;
    while (true) {
        s.pop_back();
        if (s.size()%2==1) s.pop_back();
        int h = s.size()/2;
        bool tf = true;
        for (int i = 0; i < h; i++) {
            if (s[i] != s[i+h] ) {tf = false; break;}
        }
        if (tf) break;
    }
    cout << s.size() << endl;
    return 0;
}