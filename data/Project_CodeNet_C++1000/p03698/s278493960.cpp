#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool varied = true, a[26];
    for (int i = 0; i < 26; i++) a[i] = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (a[s[i] - 97] == true)
        {
            cout << "no";
            varied = false;
            break;
        }
        else a[s[i] - 97] = true;
    }
    if (varied == true) cout << "yes";
}