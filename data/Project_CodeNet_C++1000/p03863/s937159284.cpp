#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s;
    cin >> s;
    bool res = true;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        if(i & 1 && s[i] != s[1])res = false;
        if(i % 2 == 0 && s[i] != s[0])res = false;
    }
    if(res) {
        cout << "Second" << endl;
        return 0;
    } else {
        if(s[0] != s[n - 1]) {
            cout << (n & 1 ? "First" : "Second") << endl;
        } else {
            cout << (n & 1 ? "Second" : "First") << endl;
        }
    }
}