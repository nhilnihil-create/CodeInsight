#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

ll dp[55][55][55*55]={};

int main(void) {
  ll i, j, k;
  ll N, A;
  cin >> N >> A;
  ll x[55];
  
  for(i=0; i<N; i++) cin >> x[i];
  
  dp[0][0][0]=1;
  for(i=0; i<N; i++) {
    for(j=0; j<=N; j++) {
      for(k=0; k<55*55; k++) {
        dp[i+1][j][k]+=dp[i][j][k];
        dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
      }
    }
  }
  
  ll ans=0;
  for(j=1; j<=N; j++) ans+=dp[N][j][j*A];
  
  pt(ans);
}

