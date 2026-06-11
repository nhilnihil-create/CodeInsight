#include <bits/stdc++.h>
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

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i,N){
        cin >> v[i];
    }
    vector<vector<ll>> dp(N+1,vector<ll>(N+1));
    rep(i,N){
        rep(j,N){
            cmax(dp[i+1][j+1], dp[i][j+1]);
            cmax(dp[i+1][j+1], dp[i][j] + v[i]);
        }
    }
    ld Mave = 0;
    ll rec_i = -1;
    REP(i,A,B+1){
        if(Mave < ld(dp[N][i])/ld(i)){
            rec_i = i;
            Mave = ld(dp[N][i])/ld(i);
        }
    }
    cout << setprecision(30) << Mave << endl;
    sort(v.rbegin(), v.rend());
    ll sum = 0;
    ll c = v[A-1];
    ll chose = 0;
    rep(i,A){
        if(c == v[i]){
            chose++;
        }
    }
    ll cand = 0;
    REP(i,0,N){
        if(c == v[i]){
            cand++;
        }
    }
    ll ans = 0;
    if(c == v[0]){
        ans = 0;
        ll tmp = 1;
        rep(i, A){
            tmp *= (cand-i);
            tmp /= (i+1);
        }
        REP(i, A, B+1){
            ans += tmp;
            tmp *= (cand-i);
            tmp /= (i+1);
        }
        cout << ans << endl;
        return 0;
    }
    ll tmp = 1;
    rep(i,chose){
        tmp *= (cand-i);
        tmp /= (i+1);
    }
    ans = tmp;
    cout << ans << endl;
}