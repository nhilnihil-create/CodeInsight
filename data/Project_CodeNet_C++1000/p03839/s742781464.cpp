#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T> 
void print(vector<T> &x) {
    int n = x.size();
    REP(i,n) {
        if (i != n-1) cout << x[i] << " ";
        else cout << x[i] << endl;
    }
}

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), accum_k(n+1), accum_p(n+1);
    REP(i,n) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        accum_k[i+1] = accum_k[i]+a[i];
        accum_p[i+1] = accum_p[i]+max(a[i],0ll);
    }

    ll ans = 0ll;

    for (int i = k; i <= n; ++i) {
        ll tmp1 = 0;
        // printf("i = %d accum_k[i] = %lld accum_k[i-k] = %lld\n", i,accum_k[i],accum_k[i-k]);
        // printf("i = %d accum_p[i-1] = %lld accum_p[0] = %lld accum_p[n] = %lld accum_p[k] = %lld\n", i,accum_p[i-1],accum_p[0], accum_p[n], accum_p[k]);
        tmp1 += accum_k[i]-accum_k[i-k];
        tmp1 += accum_p[i-k]-accum_p[0];
        tmp1 += accum_p[n]-accum_p[i];
        ll tmp2 = 0;
        tmp2 += accum_p[i-k]-accum_p[0];
        tmp2 += accum_p[n]-accum_p[i];
        ans = max(ans, max(tmp1, tmp2));
    }

    cout << ans << endl;
    return 0;
}