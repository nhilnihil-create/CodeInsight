#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 100000 * 10000 + 7;
int n, a[N];

int main() {
    //freopen("MA.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int k = 0; a[k] = -1;
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = 1LL * res * (i - k) % mod;
        if (a[i] - 1 < 2 * (i - k - 1)) k++;
    }
    cout << res << endl;
}
