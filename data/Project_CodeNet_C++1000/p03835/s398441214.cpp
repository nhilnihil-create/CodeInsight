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

int main()
{
    int K,S;
    cin >> K >> S;
    vint sum(3*K+1,0);
    REP(i,K+1){
        REP(j,K+1){
            sum[i+j]++;
        }
    }
    ll ans = 0;
    for(int i=0; i<=2*K && S >= i; i++){
        if(S-i <= K)ans += sum[i];
    }
    cout << ans << endl;
}