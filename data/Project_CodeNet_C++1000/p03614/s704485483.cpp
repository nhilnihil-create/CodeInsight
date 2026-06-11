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
   ll A[N];
   rep(i,N) {
      ll p;
      cin>>p;
      A[i] = p-(i+1);
   }
   ll now = 0;
   ll ans = 0;
   rep(i,N) {
      if (A[i]==0) now++;
      if (A[i]!=0 || i==N-1) {
         ans += (now+1)/2;
         now = 0;
      }
   }
   cout<<ans<<endl;


   return 0;
}