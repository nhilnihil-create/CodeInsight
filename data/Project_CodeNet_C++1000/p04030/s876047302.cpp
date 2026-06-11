#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, c;
    cin >> s;
    for (long unsigned i = 0; i < s.length(); ++i)
    {
        if (s[i] == '1') c += '1';
        if (s[i] == '0') c += '0';
        if (s[i] == 'B')
        {
            if (c[0] != '\0')
                c.erase(c.end() - 1);
        }
    }
    cout << c;
}