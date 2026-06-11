// Crt. 2019-12-17  08:10:43
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

ll n;
int cl[200], cr[200], lc, rc;

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n, ++n;

    int cnt = 101;
    while (n > 1) {
        if (n & 1) cl[++lc] = --cnt, --n;
        else cr[++rc] = --cnt, n >>= 1;
    }

    cout << 202 - 2 * cnt << endl;

    for (int i = 1; i <= lc; ++i)
        cout << cl[i] << " ";
    for (int i = rc; i >= 1; --i)
        cout << cr[i] << " ";
    for (int i = cnt; i <= 100; ++i)
        cout << i << " ";

    return 0;
}
