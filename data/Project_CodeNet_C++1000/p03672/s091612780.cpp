#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool even = false;
    for (int i = n - 2; i > 0; i = i - 2)
    {
        bool same = true;
        for (int j = 0; j < i / 2; j++)
        {
            if (s[j] != s[j + i / 2])
            {
                same = false;
                break;
            }
        }
        if (same == true)
        {
            cout << i;
            break;
        }
    }
}