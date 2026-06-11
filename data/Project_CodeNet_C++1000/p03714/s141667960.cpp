#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> a(3 * n);
    rep(i, 3 * n) cin >> a[i];
    
    vector<ll> L(3 * n);
    priority_queue<ll, vector<ll>, greater<ll>> que;

    ll sum = 0;
    rep(i, a.size()) {
        que.push(a[i]);
        sum += a[i];
        if (que.size() > n) {
            ll v = que.top(); // minimum
            sum -= v;
            que.pop();
        }
        L[i] = sum;
    }
    
    vector<ll> R(3 * n);
    priority_queue<ll, vector<ll>, less<ll>> queR;

    sum = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        queR.push(a[i]);
        sum += a[i];
        if (queR.size() > n) {
            ll v = queR.top(); // maxmam
            sum -= v;
            queR.pop();
        }
        R[i] = sum;
    }

    ll res = -1e18;
    for (int i = n-1; i < 2 * n; i++) {
        ll score = L[i] - R[i+1];
        res = max(res, score);
    }

    put(res);
    
}
signed main(){ Main();return 0;}