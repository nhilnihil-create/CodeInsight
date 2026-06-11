#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;cin>>n>>k;
  vector<int>a(n);
  int res=0;
  rep(i,n)cin>>a[i];
  sort(all(a));
  vector<int>need(k+1,-1);
  rep(i,n){
    vector<int>dp(k);
    int f=0,ma=0;
    dp[0]=1;
    if(a[i]>k&&need[k]!=-1){res+=need[k];continue;}
    if(a[i]<=k&&need[a[i]]!=-1){res+=need[a[i]];continue;}
    rep(j,n){
      if(j==i)continue;
      if(a[j]>=k)break;
      auto tdp=dp;
      rep(l,min(ma+1,k-a[j])){
        if(!dp[l])continue;
        tdp[l+a[j]]=1;
        chmax(ma,l+a[j]);
        if(ma>=k-a[i])break;
      }
      if(ma>=k-a[i])break;
      dp=tdp;
    }
    f=(ma>=k-a[i]);
    if(!f)need[min(k,a[i])]=1;
    else need[min(k,a[i])]=0;
    res+=need[min(k,a[i])];

  }
  //rep(i,k+1)cout<<need[i]<<endl;
  cout<<res<<endl;

  return 0;

}
