#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
constexpr int MOD = 1000000007;

int mod(const ll &x){
    return x > 0 ? x % MOD : (x+MOD) % MOD;
}

int modm(const ll &x,const ll &m){
    return (x % MOD) * (m % MOD) % MOD;
}

int modpow(ll x, ll p) {
    int ret = 1;
    while(p > 0) {
        if (p & 1) ret = modm(ret,x);
        x = modm(x,x);
        p >>= 1;
    }
    return ret;
}

// x * modinv(d)
int modd(ll x,ll d) {
    return modm(x,modpow(d,MOD-2));
}

int main(void)
{
    IOS
    int n; cin >> n;
    vector<int> t(n), a(n);
    REP(i,n) cin >> t[i];
    REP(i,n) cin >> a[i];

    int ans = 1;
    if (t[n-1] != a[0]) {
        ans = 0;
    } else {
        REP(i,n) {
            if(i != 0 && t[i] > t[i-1]) {
                if (t[i] > a[i]) {
                    ans = 0;
                    break;
                }
            } 
            if(i != n-1 && a[i+1] < a[i]) {
                if (t[i] < a[i]) {
                    ans = 0;
                    break;
                }
            }
            int m = 0;
            if (i == 0 || i == n-1 || t[i] > t[i-1] || a[i+1] < a[i]) {
                m = 1;
            } else {
                m = min(t[i],a[i]);
            }
            ans = modm(ans,m);
        }
    }

    cout << ans << '\n';

    return 0;
}