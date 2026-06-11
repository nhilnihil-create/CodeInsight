#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
constexpr ll MOD = 1000000007;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<tuple<ll,ll,ll>>>;

ll modpow(ll a,ll n,ll m){//modpow(a,n,m) := a ^ n (mod m)
  ll res = 1;
  while(n > 0){
    if(n & 1)res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),T(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> T[i];
    ll AX = 0,BX = 0,AM = 0,BM = 0;
    rep(i,N){
        if(AM < A[i]){
            AM = A[i];
            AX = i;
        }
    }
    rrep(i,N){
        if(BM < T[i]){
            BM = T[i];
            BX = i;
        }
    }
    if(AM != BM || AX > BX){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    ans *= max(0LL,modpow(AM,(BX-AX-1),MOD));
    ans %= MOD;
    ll memo = 0,cnt = 0;;
    FOR(i,0,AX){
        memo = A[i];
        cnt = 0;
        while(memo >= A[i]){
            cnt++;
            i++;
        }
        i--;
        ans *= modpow(memo,cnt-1,MOD);
        ans %= MOD;
    }
    RFOR(i,BX+1,N){
        memo = T[i];
        cnt = 0;
        while(memo >= T[i]){
            cnt++;
            i--;
        }
        i++;
        ans *= modpow(memo,cnt-1,MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}
