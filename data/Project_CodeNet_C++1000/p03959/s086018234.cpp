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
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pint pair<int,int>
#define pll pair<ll,ll>
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  cin >> n;
  int t[n];
  rep(i,n)cin >> t[i];
  int a[n];
  rep(i,n)cin >> a[i];
  ll ans=1;
  bool flag[n]={},flag2[n]={};
  int sup[n]={};
  rep(i,n){
    if(i==0){
      flag[i]=true;
    }
    else{
      if(t[i]>t[i-1]){
        flag[i]=true;
      }else{
        sup[i]=t[i];
      }
    }
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1){
      flag2[i]=true;
    }
    else{
      if(a[i]>a[i+1]){
        flag2[i]=true;
      }else{
        if(!flag[i]){
          sup[i]=min(sup[i],a[i]);
        }else{
          if(t[i]>a[i]){
            cout << 0 << endl;
            return 0;
          }
        }
      }
    }
  }
  rep(i,n){
    if(!flag[i] && !flag2[i]){
      ans*=sup[i];
      ans%=mod;
    }
  }
  if(t[n-1]!=a[0])ans=0;
  cout << ans << endl;
return 0;}