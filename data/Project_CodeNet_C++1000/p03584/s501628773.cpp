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

    unsigned int n, k;
    cin >> n >> k;

    map<unsigned int, ll> m;
    rep(i, 30) {
        if (k & (1 << i)) {
            unsigned int x = k - (1 << i);
            m[x | ((1 << i) - 1)] = 0;
        }
    }
    m[k] = 0;

    rep(i, n) {
        unsigned int a, b;
        cin >> a >> b;
        for(auto& p : m) {
            if ((p.first & a) == a) {
                p.second += b;
            }
        }
    }

    ll ans = 0;
    for(auto& p: m) {
        // cout << p.first << endl;
        ans = max(ans, p.second);
    }

    cout << ans << endl;
// 101
    return 0;
}
