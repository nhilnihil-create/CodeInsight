#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int b[n];
    rep(i, n) b[i] = 1;
    bool r[n] = {0};
    r[0] = 1;

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (r[x]) r[y] = 1;
        b[x] -= 1;
        b[y] += 1;
        if (b[x] == 0) r[x] = 0;
    }

    cout << count(r, r + n, 1) << endl;
    return 0;
}
