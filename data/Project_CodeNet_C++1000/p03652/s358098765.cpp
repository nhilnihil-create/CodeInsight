#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int inf=1000000007;
int a[305][305];
int n,m;

int solve2(vector<bool>& ok){
  int ans=0;
  vector<int> sum(m+1,0);
  rep(i,n){
    int j=0;
    while(!ok[a[i][j]]){
      j++;
    }
    sum[a[i][j]]++;
  }
  int p;
  rep1(i,m){
    if(ans<sum[i]){
      ans=sum[i];
      p=i;
    }
  }
  ok[p]=false;
  return ans;
}
int solve1(vector<bool>& ok){
  int ans=inf;
  rep(i,m){
    int buf=solve2(ok);
    if(ans>buf){
      ans=buf;
      /*
      cout<<"ok"<<endl;
      rep1(i,m){
        cout<<ok[i]<<endl;
      }
      cout<<"ans"<<endl;
      cout<<ans<<endl;
      */
    }
    //ans=min(ans,solve2(ok));
  }
  return ans;
}
signed main(){
  cin>>n>>m;
  vector<bool> ok(m+1,true);
  rep(i,305){
    rep(j,305){
      a[i][j]=0;
    }
  }
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }
  int ans=solve1(ok);
  //cout<<"ans"<<endl;
  cout<<ans<<endl;
  return 0;
}
