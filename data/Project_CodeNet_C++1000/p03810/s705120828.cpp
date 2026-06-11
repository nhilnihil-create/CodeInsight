/* be name khoda */
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

#define forifrom(i, s, n) for (ll i = s; i < n; ++i)
#define fori(i, n) forifrom(i, 0, n)
#define forirto(i, n, e) for (ll i = (n) - 1; i >= e; --i)
#define forir(i, n) forirto(i, n, 0)

typedef pair<ll, ll> pii;

#define eb emplace_back
#define S second
#define F first
#define all(x) (x).begin(), (x).end()

// ------------------------------------------------------------------

const ll maxn = 100010;

ll n, A[maxn];

// 0 -> First Lose, 1 -> First Win
ll solve() {
    ll s = 0, o = -1; // we have at least one odd number (gcd = 1)
    fori (i, n) {
        s += A[i] - 1;
        if (A[i] % 2) {
            if (o == -1) o = i;
            else o = n;
        }
    }
    if (s % 2) return 1;
    else if (o == n || A[o] == 1) return 0;
    else {
        --A[o];
        ll g = 0;
        fori (i, n) g = __gcd(g, A[i]);
        fori (i, n) A[i] /= g;
        return 1 ^ solve();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    fori (i, n) cin >> A[i];
    ll r = solve();
    cout << (r ? "First\n" : "Second\n");

}
