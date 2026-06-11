#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
const ul mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }

    vector<ll> index(n);
    iota(index.begin(), index.end(), 0);

    sort(index.begin(), index.end(),
         [&](const int &x, const int &y) { return a[x] < a[y]; });

    ll count = 0;
    rep(i, n) { count += abs(index[i] - i) % 2; }
    cout << count / 2 << endl;
    return 0;
}

