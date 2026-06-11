#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int k = 0;
    if (s[0] == s[s.length() - 1]) k++;
    k += s.length() % 2;
    if (k % 2 == 0) cout << "Second";
    else cout << "First";
}