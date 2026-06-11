#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b = vi(a);
    sort(all(b));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(all(b), a[i]) - b.begin();
        if (idx % 2 != i % 2) ans++;
    }

    cout << ans / 2 << endl;

    return 0;
}
