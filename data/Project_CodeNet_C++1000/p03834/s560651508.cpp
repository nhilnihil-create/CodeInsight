#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string s;

int main() {
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(i == 5 || i == 13) cout << " ";
        else if(i == s.length()-1) cout << s.at(i) << endl;
        else cout << s.at(i);
    }
}