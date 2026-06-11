#define rep(i,n) REP(i,0,n)
#define REP(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;

// const ll MAXN = (ll)1e3+10;
const ll DIV = (ll)1e9+7;
// ll dp[MAXN][MAXN];

int main(void) {
   ll N;
   cin>>N;
   vector<vector<ll>> A;
   A.resize(N);
   rep(i,N) A[i].resize(N);
   rep(i,N) rep(j,N) cin>>A[i][j];

   multimap<ll,ll> As;
   rep(i,N) {
      for (int j = i+1; j<N;j++) {
         As.insert(make_pair(A[i][j],i*N+j));
      }
   }

   vector<vector<ll>> L;
   L.resize(N);
   rep(i,N) L[i].resize(N);
   rep(i,N) rep(j,N) L[i][j] = INF;
   rep(i,N) L[i][i] = 0;

   ll ans = 0;
   for (auto itr = As.begin();itr!=As.end();itr++) {
      int i = (itr->second)%N;
      int j = (itr->second)/N;
      int len = itr->first;
      if (L[i][j] == len) continue;
      else if (L[i][j] < len){
         ans =-1;
         break; 
      } else {
         // connect i,j with len.
         ans += len;

         rep(k,N) rep(l,N) {
            chmin(L[k][l],L[k][i]+len+L[l][j]);
            chmin(L[k][l],L[k][j]+len+L[l][i]);
         }
      }
   }
   cout<<ans<<endl;

   return 0;
}