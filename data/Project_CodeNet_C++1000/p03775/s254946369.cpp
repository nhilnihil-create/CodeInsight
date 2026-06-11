#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
int f(int a,int b){
    int res=0;
    while(a>0){
        ++res;a/=10;
    }
    int buf=0;
    while(b>0){
        ++buf;b/=10;
    }
    return max(res,buf);
}
signed main(){
  lint n;cin>>n;
  lint res=inf;
  rep1(i,100000){
      if(n%i==0){
          lint buf=f(i,n/i);
          res=min(res,buf);
      }
  }
  cout<<res<<"\n";
  return 0;
}