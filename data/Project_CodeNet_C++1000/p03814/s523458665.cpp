#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int m, n;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'A')
        {
            m = i;
            break;
        }
    }
    for (int i = s.length(); i > 0; i--)
    {
        if (s[i] == 'Z')
        {
            n = i + 1;
            break;
        }
    }
    cout << n - m;
}