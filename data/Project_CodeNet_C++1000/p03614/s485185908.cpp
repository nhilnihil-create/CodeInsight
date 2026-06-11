#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MX = 100 * 1000 + 7;
int a[MX];
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            res++;
            if (i + 1 <= n && a[i + 1] == i + 1) {
                i++;
            }
        }
    }
    cout << res << endl;
}

