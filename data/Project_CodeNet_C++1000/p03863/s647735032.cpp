#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s;
    cin >> s;
    int n = s.size();

    if(n & 1) {
        cout << (s[0] == s[n - 1] ? "Second" : "First") << endl;
    } else {
        cout << (s[0] == s[n - 1] ? "First" : "Second") << endl;
    }
}