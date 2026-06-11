#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    regex re("^(dream|dreamer|erase|eraser)+$");
    cout << (regex_match(s, re) ? "YES\n" : "NO\n");
    return 0;
}