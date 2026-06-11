#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define pll pair<ll, ll>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, N) {
        cin >> a[i];
        b[i] = a[i];
    }

    ll tmp1 = 0, tmp2 = 0, ans = 0;
    rep(i, N) {
        if (i % 2 == 0) {
            if (a[i] <= 0)
                tmp1 += (1 - a[i]), a[i] = 1;
            if (b[i] >= 0)
                tmp2 += (b[i] + 1), b[i] = -1;
        } else {
            if (a[i] >= 0)
                tmp1 += (a[i] + 1), a[i] = -1;
            if (b[i] <= 0)
                tmp2 += (1 - b[i]), b[i] = 1;
        }

        if (i != N - 1)
            a[i + 1] += a[i], b[i + 1] += b[i];
    }

    ans = min(tmp1, tmp2);
    cout << ans << endl;
    return 0;
}