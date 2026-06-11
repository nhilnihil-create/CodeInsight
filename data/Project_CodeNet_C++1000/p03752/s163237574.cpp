#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
#define P(a,b) make_pair(a,b);
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll ans = INF;
    vector<ll> B(N);
    rep(i,(1LL<<N)){
        rep(i,N) B[i] = A[i];
        if(__builtin_popcountll(i) == K){
            bitset<5> S(i);
            ll res = 0;
            ll M = 0;
            rep(j,N){
                if((i >> j) & 1){
                    res += max(0LL,M - A[j]+1);
                    M = max(M+1,A[j]);
                }
                M = max(M,A[j]);
            }
            ans = min(ans,res);
        }
    }
    cout << ans << endl;
}
