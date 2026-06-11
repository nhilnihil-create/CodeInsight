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
  int n,k;
  cin >> n >> k;
  ll a[n+1]={};
  rep(i,n)cin >> a[i+1];
  ll sum[n+1]={},posisum[n+1]={};
  rep(i,n){
    sum[i+1]=sum[i]+a[i+1];
    posisum[i+1]=posisum[i]+max(0LL,a[i+1]);
  }
  ll ans=-longinf;
  for(int i=1;i+k<=n+1;i++){
    ans=max(ans,max(0LL,(sum[i+k-1]-sum[i-1]))+posisum[i-1]+posisum[n]-posisum[i+k-1]);
  }
  cout << max((ll)0,ans) << endl;
return 0;}