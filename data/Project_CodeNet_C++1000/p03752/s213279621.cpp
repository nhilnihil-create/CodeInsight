#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

int main()
{
  int N,K;
  cin >> N >> K;
  vll A(N);
  cin >> A;
  
  ll ans = LLONG_MAX;
  REP(i,1<<N){
    if(counter(i) < K)continue;
    vint v;
    REP(j,N)if(i & (1<<j))v.pb(j);
    ll cost=0;
    ll pre = -1LL;
    REP(j,v.size()){
      ll ma=pre;
      for(int k=(j?v[j-1]:0); k<v[j];k++)chmax(ma,A[k]);
      cost += max(0LL,ma-A[v[j]]+1);
      pre=max(ma+1,A[v[j]]);
    }
    chmin(ans,cost);
  }
  cout << ans << endl;
}