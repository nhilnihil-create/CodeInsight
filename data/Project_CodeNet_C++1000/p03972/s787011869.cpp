#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll& b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll& b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
int main(){
    cin >> w >> h;
    vl A;
    rep(i, w) {
        cin >> x;
        A.push_back(x * 10 + 1);
    }
    rep(i, h) {
        cin >> x;
        A.push_back(x * 10 + 2);
    }

    sort(all(A));
    a = h+1;
    b = w+1;
    rep(i, h + w) {
        if (A[i] % 10 == 1) {
            x = A[i] / 10;
            ans += x * a;
            b--;
        }
        else {
            x = A[i] / 10;
            ans += x * b;
            a--;
        }
    }
    
    cout<<ans<<endl;
}
