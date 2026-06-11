#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int c[9];

int main() {
    int n;
    cin >> n;

    rep(i, n) {
        int a;
        cin >> a;
        if (a >= 3200)
            c[8]++;
        else
            c[a / 400]++;
    }

    int minv = 0, maxv = 0;
    rep(i, 8) if (c[i]) minv++, maxv++;
    maxv += c[8];
    if (minv == 0) minv = 1;

    cout << minv << ' ' << maxv << endl;
    return 0;
}
