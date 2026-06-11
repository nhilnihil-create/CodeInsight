#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
signed main(){
  int n,k;
  cin>>n>>k;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i],as[i]--;

  vector< vector<int> > G(n);
  for(int i=1;i<n;i++)
    G[as[i]].emplace_back(i);

  int ans=as[0]!=0;
  MFP([&](auto dfs,int v,int p)->int{
        int res=1;
        for(int u:G[v])
          chmax(res,dfs(u,v)+1);

        if(res==k&&p>0){
          ans++;
          res=0;
        }

        return res;
      })(0,-1);

  cout<<ans<<endl;
  return 0;
}
