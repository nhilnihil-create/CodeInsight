#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  vector< vector<int> > G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int q;
  cin>>q;
  vector<int> us(q),ds(q),cs(q);
  for(int i=0;i<q;i++) cin>>us[i]>>ds[i]>>cs[i],us[i]--;

  vector< vector<int> > dp(11,vector<int>(n,-1));
  using P = pair<int, int>;
  vector< queue<P> > qs(11);
  for(int i=0;i<q;i++){
    chmax(dp[ds[i]][us[i]],i);
    qs[ds[i]].emplace(us[i],i);
  }

  for(int d=10;d>0;d--){
    queue<P> que=qs[d];
    while(!que.empty()){
      int v,i;
      tie(v,i)=que.front();que.pop();
      if(dp[d][v]!=i) continue;
      for(int u:G[v]){
        if(dp[d-1][u]==i) continue;
        chmax(dp[d-1][u],i);
        qs[d-1].emplace(u,i);
      }
      if(dp[d-1][v]==i) continue;
      chmax(dp[d-1][v],i);
      qs[d-1].emplace(v,i);
    }
  }

  for(int i=0;i<n;i++)
    cout<<(~dp[0][i]?cs[dp[0][i]]:0)<<endl;
  return 0;
}
