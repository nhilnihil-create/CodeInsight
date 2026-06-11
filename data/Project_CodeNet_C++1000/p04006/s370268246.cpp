#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<memory.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  ll x;
  cin >> n >> x;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  ll ans=longinf;
  ll dp[n][n]={}; //dp[i][j]:the minimum of the time to chatch i-th monster whitin j-times rotation
  rep(i,n)rep(j,n)dp[i][j]=longinf;
  rep(i,n)dp[i][0]=a[i];
  for(int i=0;i<n;i++){
    for(int j=1;j<n;j++){
      ll temp=a[(i+j)%n];
      dp[i][j]=min(dp[i][j-1],temp);
    }
  }
  for(int i=0;i<n;i++){ //the times of rotations
    ll res=i*x;
    rep(j,n){
      res+=dp[j][i];
    }
    ans=min(ans,res);
  }
  cout << ans << endl;
return 0;}