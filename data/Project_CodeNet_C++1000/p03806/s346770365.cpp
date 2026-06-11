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
  int n,ma,mb;
  cin>>n>>ma>>mb;
  vector<vector<int>>dp(401,vector<int>(401,1e9));
  dp[0][0]=0;
  rep(i,n){
    int a,b;cin>>a>>b;
    int c;cin>>c;
    auto tdp=dp;
    rep(j,401-a)rep(k,401-b){
      if(dp[j][k]!=1e9)chmin(tdp[j+a][k+b],dp[j][k]+c);
    }
    dp=tdp;
  }
  int res=1e9;
  int ta,tb;ta=ma;tb=mb;
  while(ta<401&&tb<401){
    chmin(res,dp[ta][tb]);
    ta+=ma;
    tb+=mb;
  }
  if(res==1e9)res=-1;
  cout<<res<<endl;

  return 0;

}
