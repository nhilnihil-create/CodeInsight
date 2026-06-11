#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool isP(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main()
{
    string s;
    cin >> s;
    cout << (isP(s) ? "Yes" : "No") << endl;
}