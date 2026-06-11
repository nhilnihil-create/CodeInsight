#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X,i) ((X>>i)&1)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(rall(a))
#define ina(x,n) rep(x_i,n) cin>>x[x_i]
#define outa(x,n) rep(x_i,n) cerr<<x[x_i]<<" \n"[x_i==n-1]

using ll  = long long int;
using vl  = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int inf = (1<<28);
const ll infl = (1LL<<60);

int main() {
    int N, L, Q; cin >> N;
    vl x(N); ina(x, N);
    vvl dp(N, vl(50));
    cin >> L >> Q;
    rep(i,N) {
        dp[i][0] = upper_bound(all(x), x[i]+L)-x.begin() - 1;
    }
    rep(k,40) rep(i,N) {
        dp[i][k+1] = dp[dp[i][k]][k];
    }

    rep(i,Q) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        ll ans = 1;
        while (dp[a][0] < b) {
            int k = lower_bound(all(dp[a]), b)-dp[a].begin() - 1;
            a = dp[a][k];
            ans += pow(2, k);
        }
        cout << ans << endl;
    }
    return 0;
}
