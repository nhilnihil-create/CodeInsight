#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll modpow(ll a,ll n,ll m){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int main(){
    ll N,AX,BX,AM = 0,BM = 0;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N){
        cin >> A[i];
        if(AM < A[i]){
            AX = i;AM = A[i];
        }
    }
    rep(i,N){
        cin >> B[i];
    }
    rrep(i,N){
        if(BM < B[i]){
            BM = B[i];BX = i;
        }
    }
    if(AM != BM || BX < AX){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    if(AX < BX){
        ans *= modpow(AM,BX-AX-1,MOD);
    }
  	ans %= MOD;
    vector<pair<ll,ll>> C,D;
    C.emplace_back(1,1);
    D.emplace_back(1,1);
    RFOR(i,1,AX+1){
        if(A[i] == A[i-1])C.back().first++;
        else C.emplace_back(1,A[i-1]);
    }
    FOR(i,BX,N-1){
        if(B[i] == B[i+1]) D.back().first++;
        else D.emplace_back(1,B[i+1]);
    }
    rep(i,C.size()){
        ans *= modpow(C[i].second,C[i].first-1,MOD);
        ans %= MOD;
    }
    rep(i,D.size()){
        ans *= modpow(D[i].second,D[i].first-1,MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}
