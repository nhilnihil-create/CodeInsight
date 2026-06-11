#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, s, d = 0;
    cin >> k >> s;
    for (int i = 0; i <= k; i++)
    {
        if (s - i <= k * 2 && s - i >= 0)
            d += min(s - i, k) - max(0, s - i - k) + 1;
    }
    cout << d;
}