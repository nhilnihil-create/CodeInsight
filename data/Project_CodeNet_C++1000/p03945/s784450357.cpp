#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int x=0;
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i]!=s[i+1]) x++;
    }
    cout << x << endl;
    return 0;
}