#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = (int)s.size();
    if (len < 4) cout << "No" << endl;
    else {
        string t;
        for (int i = 0; i < 4; i++) {
            t += s.at(i);
        }
        if (t == "YAKI") cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
}   