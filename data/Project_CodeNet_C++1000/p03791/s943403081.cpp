#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    int N;
    cin >> N;
    vector<ll> X(N);
    REP(i,N)cin >> X[i];
    vector<ll> COMP(0);
    COMP.pb(1);
    X[0] = 1;
    REPS(i,N-1){
        if(X[i] != X[i-1] + 1){
            X[i] = X[i-1] + 2;
        }
    }
    ll dou = 1;
    REPS(i,N-1){
        if(X[i] != X[i-1] + 1){
            (*COMP.rbegin())++;
        }else{
            dou++;
            if(dou%2 == 0){
                (*COMP.rbegin())++;
                COMP.pb(0);
            }else{
                (*COMP.rbegin())++;
            }
        }
    }
    ll remain = 0;
    ll ans = 1;
    REP(i,N){
        if(i < COMP.size())remain += COMP[i];
        ans = (ans * remain)%mod;
        remain--;
    }
    cout << ans << "\n";
}