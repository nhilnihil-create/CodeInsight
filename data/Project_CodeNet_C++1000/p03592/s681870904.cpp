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
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,m,k;cin>>n>>m>>k;
  bool ans=false;
  rep(i,n+1){
    rep(j,m+1){
      int sum=i*m+j*n-2*i*j;
      if(sum==k){
        ans=true;
        break;
      }
    }
  }
  	if(ans){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  return 0;
}
