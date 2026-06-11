#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int n;
string s;

int main() {
    cin >> s;
    n = s.length();
    cout << (((s[0] == s[n-1]) ^ (n % 2 == 1) ? "First" : "Second")) << endl;
}