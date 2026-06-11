#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    int N;
    cin >> N;
    vector<ll> a(3 * N);
    rep(i, 3 * N) { cin >> a[i]; }

    ll ans = 0;
    sort(all(a), greater<ll>());
    for (int i = 0; i <= 2 * N - 1; i++) {
        if (i % 2 == 0)
            continue;
        ans += a[i];
    }

    cout << ans << endl;
}