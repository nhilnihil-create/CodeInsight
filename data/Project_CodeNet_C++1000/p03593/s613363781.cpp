#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> a(26);
    rep(i, h * w) {
        char c;
        cin >> c;
        a[c - 'a']++;
    }

    int p = 0, q = 0;
    rep(i, 26) {
        if (a[i] % 4 != 0) p++;
        if (a[i] % 2 == 1) q++;
    }

    int t = ((h % 2) * w + (w % 2) * h) / 2;
    if (q <= 1 && p <= t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
