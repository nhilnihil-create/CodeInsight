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

ll dp[55][55*55*2]={};

int main(void) {
  ll i, j, k;
  ll N, A;
  cin >> N >> A;
  ll x[55];
  
  for(i=0; i<N; i++) {
    cin >> x[i];
    x[i]-=A;
  }
  
  dp[0][2500]=1;
  for(i=0; i<N; i++) {
    for(j=0; j<55*55*2; j++) {
      dp[i+1][j]+=dp[i][j];
      dp[i+1][j+x[i]]+=dp[i][j];
    }
  }
  
  pt(dp[N][2500]-1); //-1: 1枚も選ばない場合
}

