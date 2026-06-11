#include <bits/stdc++.h>
using namespace std;
int main() {
    string w;
    int s[26], k = 0;
    cin >> w;
    for (int i = 0; i < 26; ++i) s[i] = 0;
    for (long unsigned i = 0; i < w.length(); ++i)
    {
        s[w[i] - 97]++;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (s[i] % 2 == 1)
        {
            k++;
            cout << "No";
            break;
        }
    }
    if (k == 0) cout << "Yes";
}