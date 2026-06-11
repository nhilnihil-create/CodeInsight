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
signed main(){
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n)cin>>p[i];
  vector<int> a(n+1,0);
  rep1(i,n){
      a[i]=2*n*i;
  }
  int sum=2*n*n+n;
  vector<int> b(n+1,0);
  reverse(ALL(p));
  rep(i,n){
      b[p[i]]=sum-a[p[i]];
      --sum;
  }
  rep1(i,n){
      cout<<a[i]<<" ";
  }
  cout<<endl;
  rep1(i,n){
      cout<<b[i]<<" ";
  }
  cout<<endl;
  return 0;
}