#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<vector<Int> > G(n);
  for(Int i=1;i<n;i++){
    Int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  
  function<Int(Int, Int) > dfs=
    [&](Int v,Int p)->Int{
      Int cnt=0;
      for(Int u:G[v])
        if(u!=p) cnt++;

      if(cnt==0) return 0;

      if(cnt==1){
        for(Int u:G[v])
          if(u!=p) return dfs(u,v)+1;
      }
      
      Int res=0;
      for(Int u:G[v])
        if(u!=p) res^=dfs(u,v)+1;
      
      return res;
    };
  
  cout<<(dfs(0,-1)?"Alice":"Bob")<<endl;
  return 0;
}
