#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int l = 0, n = s.size(), i = 0;
    while (i < n)
    {
        while (s[i] == 'B' && i < n)
            --l, ++i;
        if (l < 0) l = 0;
        if (s[i] == '0' || s[i] == '1')
            s[l] = s[i], ++l, ++i;
    }
    for (int i = 0; i < l; ++i)
        cout << s[i];
}