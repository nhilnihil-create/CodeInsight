#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
//using namespace atcoder;
ll dp[43][500][500];

int main(){
    int N,Ma,Mb;
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];
    }
    rep(i,43)rep(j,500)rep(k,500){
        dp[i][j][k] = 1e18;
    }
    dp[0][0][0] = 0;
    rep(i,N){
        rep(j,402){
            rep(k,402){
                cmin(dp[i+1][j][k], dp[i][j][k]);
                cmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
            }
        }
    }
    ll ma = Ma;
    ll mb = Mb;
    ll ans = 1e18;
    rep(i,400){
        if(ma > 400 || mb > 400)break;
        rep(j,N){
            cmin(ans, dp[j+1][ma][mb]);
        }
        ma += Ma;
        mb += Mb;
    }
    if(ans == 1e18){
        ans = -1;
    }    
    cout << ans << endl;
    /*
    ll n1 = N/2;
    ll n2 = N - N/2;
    vector<vector<ll>> v(405, vector<ll>(405,1e18)), u(405, vector<ll>(405,1e18)); 
    vector<Pll> vv,uu;
    rep(i,(1LL << (n1))){
        ll suma = 0;
        ll sumb = 0;
        ll sumc = 0;
        rep(j,n1){
            if((i >> j) & 1LL){
                suma += a[j];
                sumb += b[j];
                sumc += c[j];
            }
        }
        v[suma][sumb] = sumc;
        vv.push_back({suma,sumb});
    }
    rep(i,(1LL << (n2))){
        ll suma = 0;
        ll sumb = 0;
        ll sumc = 0;
        REP(j,0,n2){
            if((i >> j) & 1LL){
                suma += a[j+n1];
                sumb += b[j+n1];
                sumc += c[j+n1];
            }
        }
        u[suma][sumb] = sumc;
        uu.push_back({suma,sumb});
    }
    ll ans = 1e18;
    rep(i, vv.size()){
        ll at = vv[i].fi;
        ll bt = vv[i].se;
        ll ma = Ma;
        ll mb = Mb;
        rep(j,1000){
            ll ca = ma - at;
            ll cb = mb - bt;
            if((0 <= ca && ca <= 400)){
                if((0 <= cb && cb <= 400)){
                    if((0 <= at && at <= 400)){
                        if((0 <= bt && bt <= 400)){
                            cmin(ans, u[ca][cb] + v[at][bt]);
                        }
                    }
                }
            }
            gt:
            ma += Ma;
            mb += Mb;
        }
    }
    if(ans == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;*/
}