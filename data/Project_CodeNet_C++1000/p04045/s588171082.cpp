#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int d[k];
    rep(i, k) cin >> d[i];

    for (int i = n; i < 100000; i++) {
        int x = i;
        bool ok = true;
        while (x > 0) {
            rep(j, k) if (x % 10 == d[j]) ok = false;
            x /= 10;
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
