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
void solve(int n,int x){
    vector<int> res(2*n+5,0);
    if(x==2){
        res[n]=x;
        res[n+1]=1;
        int cur=3;
        rep1(i,2*n-1){
            if(res[i]!=0)continue;
            res[i]=cur;
            ++cur;
        }
    }
    else{
        res[n]=x;
        res[n+1]=2*n-1;
        res[n-1]=1;
        res[n+2]=2;
        int cur=3;
        rep1(i,2*n-1){
            if(res[i]!=0)continue;
            if(cur==x)++cur;
            res[i]=cur;
            ++cur;
        }
    }
    rep1(i,2*n-1){
        cout<<res[i]<<"\n";
    }
}
signed main(){
  int n,x;cin>>n>>x;
  if(n==2&&x==2){
      cout<<"Yes"<<"\n";
      rep1(i,2*n-1){
          cout<<i<<"\n";
      }
  }
  else if(n==2&&x!=2){
      cout<<"No"<<"\n";
  }
  else{
      if(x==1||x==2*n-1){
          cout<<"No"<<"\n";
      }
      else{
          cout<<"Yes"<<endl;
          solve(n,x);
      }
  }
  return 0;
}