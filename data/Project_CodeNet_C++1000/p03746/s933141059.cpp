#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int> > G(n);

  vector<int> used(n,0);
  deque<int> ans;
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);

    if(i) continue;
    ans.emplace_front(a);
    ans.emplace_back(b);
    used[a]=used[b]=1;
  }
  
  while(1){
    int v=ans.front();
    int idx=-1;
    for(int u:G[v])
      if(!used[u]) idx=u;
    if(idx<0) break;
    ans.emplace_front(idx);
    used[idx]=1;
  }

  while(1){
    int v=ans.back();
    int idx=-1;
    for(int u:G[v])
      if(!used[u]) idx=u;
    if(idx<0) break;
    ans.emplace_back(idx);
    used[idx]=1;
  }
  
  cout<<ans.size()<<endl;
  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}
