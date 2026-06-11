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

int n, m;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> m;
    vvi a(n, vi(m, 0));
    rep(i, n) rep(j, m) {
        cin >> a[i][j];
        a[i][j]--;
    }

    int ans = n;

    vi is(n, 0);
    set<int> removed;
    rep(i, m) {
        vpii b(m);
        rep(j, m) b[j].second = j;
        rep(j, n) {
            b[a[j][is[j]]].first++;
        }

        sort(rall(b));
        ans = min(ans, b[0].first);
        removed.insert(b[0].second);

        // cout << b[0].second << " is inserted." << endl;
        rep(j, n) {
            for (auto it = removed.find(a[j][is[j]]); it != removed.end(); it = removed.find(a[j][is[j]])) {
                is[j]++;
            }
        }
    }

    // rep(i, n) {
    //    cout << i << " " << is[i] << endl;
    // }

    cout << ans << endl;

    return 0;
}
