#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for(long long i = (n-1);i>=0;i--)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;
  
  vector <int>card(n);

  REP(i,n){
    cin >> card[i];
  }
  
  sort(card.begin(),card.end());

  //card[i]を除くk-card[i]以上の部分和の最小値がk以上のとき，card[i]は不要
  //DPを用いたO(n^2)解を2分探索
  int l = -1, r = n;
  while(r-l > 1){
    int i = (r+l)/2;
    int dp[k+1] = {};
    bool flag = true;
    dp[0] = 1;
    REP(j,n){
      if(j != i){
        RREP(jj,k+1){
          if(jj-card[j] < 0) break;
          if(dp[jj-card[j]] != 0) dp[jj]++;
        }
      }
    }
    
    int check = k - min(card[i],k);
    while(flag && check < k){
      if(dp[check] > 0) flag = false;
      check++;
    }
    if(flag) l = i;
    else r = i;
  }
  
  cout << r << endl;

  return 0;
}
