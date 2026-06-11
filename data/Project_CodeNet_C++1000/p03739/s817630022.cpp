#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];
    Vl dp(n, 0);
    
    ll ans = 0;
    if(a[0] > 0) dp[0] = a[0];
    else {
        dp[0] = 1;
        ans += abs(1 - a[0]);
    }
    rep(i, 1, n){
        ll sum = dp[i-1] + a[i];
        if(dp[i-1] < 0){
            if(sum > 0) dp[i] = sum; //ok
            if(sum <= 0){
                ll ai = 1 - dp[i-1];
                ans += abs(ai - a[i]);
                dp[i] = 1;
            }
        }
        if(dp[i-1] > 0){
            if(sum < 0) dp[i] = sum; //ok
            if(sum >= 0){
                ll ai = -1 - dp[i-1];
                ans += abs(ai - a[i]);
                dp[i] = -1;
            }
        }
    }

    rep(i, 0, n) dp[i] = 0;
    ll cnt = 0;
    if(a[0] < 0) dp[0] = a[0];
    else {
        dp[0] = -1;
        cnt += abs(-1 - a[0]);
    }
    rep(i, 1, n){
        ll sum = dp[i-1] + a[i];
        if(dp[i-1] < 0){
            if(sum > 0) dp[i] = sum; //ok
            if(sum <= 0){
                ll ai = 1 - dp[i-1];
                cnt += abs(ai - a[i]);
                dp[i] = 1;
            }
        }
        if(dp[i-1] > 0){
            if(sum < 0) dp[i] = sum; //ok
            if(sum >= 0){
                ll ai = -1 - dp[i-1];
                cnt += abs(ai - a[i]);
                dp[i] = -1;
            }
        }
    }

    chmin(ans, cnt);
    co(ans);

    return 0;
}
