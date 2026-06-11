#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MOD=1e9+7;
static const ll MAX=101010;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

ll dp[66], ep[3333];

int main(void) {
  ll i, j, k, l;
  
  
  ll A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  
  dp[0]=1;
  for(i=0; i<33; i++) {
    chmax(dp[i+A], dp[i]);
    chmax(dp[i+B], dp[i]);
  }
  
  ep[0]=1;
  for(i=0; i<3030; i++) {
    chmax(ep[i+C], ep[i]);
    chmax(ep[i+D], ep[i]);
  }
  
  
  P res=P(0, 0);
  for(i=1; i<33; i++) {
    for(j=0; j<3030; j++) {
      if(i*100+j>F) continue;
      if(i*E<j) continue;
      if(!dp[i]||!ep[j]) continue;
      
      if(res.second*(i*100+j)<=(res.first+res.second)*j) {
        res=P(i*100, j);
      }
        
    }
  }
  
  pt(res.first+res.second<<" "<<res.second);
  
}


