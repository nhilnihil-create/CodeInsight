#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> v(n), w(n);
    rep(i, 0, n) cin >> v[i], v[i]--, w[v[i]] = i + 1;
    vector<ll> a(n), b(n);
    ll m = 25000;
    rep(i, 0, n)
    {
        a[i] = m * (i + 1);
        b[i] = m * (n - 1 - i) + w[i];
    }
    //ここでaは，単調増加，bは単調現象
    rep(i, 0, n) cout << a[i] << " ";
    cout << endl;
    rep(i, 0, n) cout << b[i] << " ";
    cout << endl;
}