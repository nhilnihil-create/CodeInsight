#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s.length() == 1) cout << '0';
    else
    {
        int d = 1;
        for (int i = 1; i < s.length(); i++)
            if (s[i] != s[i - 1]) d++;
        cout << d - 1;
    }
}