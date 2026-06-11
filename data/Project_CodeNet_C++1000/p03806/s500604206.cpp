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

ll dp[55][444][444];

int main(void) {
  ll i, j, k, l;
  ll N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  ll a[44], b[44], c[44];
  
  for(i=0; i<N; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  
  for(i=0; i<44; i++)
    for(j=0; j<444; j++)
      for(k=0; k<444; k++)
        dp[i][j][k]=INF;
      
  dp[0][0][0]=0;
  ll t=0;
  for(i=0; i<N; i++) {
    for(j=0; j<404; j++) {
      for(k=0; k<404; k++) {
        chmin(dp[i+1][j][k], dp[i][j][k]);
        chmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
      }
    }
  }
  
  ll ans=INF;
  for(ll p=1; p*max(Ma, Mb)<404; p++) {
    chmin(ans, dp[N][p*Ma][p*Mb]);
  }
  
  if(ans==INF) pt(-1);
  else pt(ans);
}


