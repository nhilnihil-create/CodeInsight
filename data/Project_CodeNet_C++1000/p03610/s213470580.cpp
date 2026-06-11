#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;

int main() {
    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        if(i % 2==0) {
            cout << s[i];
        }
    }
}