

#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)

#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll mod = 1e9 + 7;
const ll infl = 1e17;

int main()
{
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    vll ss(n + 1, 0);
    vll ts(m + 1, 0);
    rep(i,n){
        if (s[i]=='A'){
            ss[i + 1] = (ss[i] + 1)%3;
        }
        else {
            ss[i + 1] = (ss[i] + 2) % 3;
        }
    }
    rep(i, m)
    {
        if (t[i] == 'A')
        {
            ts[i + 1] = (ts[i] + 1) % 3;
        }
        else
        {
            ts[i + 1] = (ts[i] + 2) % 3;
        }
    }
    ll q;
    cin >> q;
    ll a, b, c, d;
    rep(i,q){
        cin >> a >> b >> c >> d;
        ll si = (3 + ss[b] - ss[a - 1]) % 3;
        ll ti = (3 + ts[d] - ts[c - 1]) % 3;
        if (si==ti)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
