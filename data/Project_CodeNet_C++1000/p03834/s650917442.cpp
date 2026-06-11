#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<char> s(19);
    for (int i = 0; i < 19; i++) {
        cin >> s.at(i);
        if (s.at(i) == ',') s.at(i) = ' ';
        
        if (i + 1 == 19) {
            cout << s.at(i) << endl;
        }
        else {
            cout << s.at(i);
        }
    }
}