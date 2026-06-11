#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

ll MOD = 1e9+7;

int main()
{
    ll N,M;
    cin >> N >> M;
    if(abs(N-M) > 1){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1LL;
    for(int i=1; i<=N; i++){
        ans *= i;
        ans %= MOD;
    }
    if(N == M){
        ans *= ans;
        ans %= MOD;
        ans *= 2;
        ans %= MOD;
    }else{
        ll cnt = 1LL;
        for(int i=1; i<=M; i++){
            cnt *= i;
            cnt %= MOD;
        }
        ans *= cnt;
        ans %= MOD;
    }
    cout << ans << endl;
}