#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i],as[i]--;

  using P = pair<Int, Int>;
  vector<P> vp;

  Int res=0;
  vector<Int> sub(m,0);
  for(Int i=0;i+1<n;i++){
    if(as[i]<as[i+1]){
      vp.emplace_back(as[i],as[i+1]);
    }else{
      res+=m-as[i]-1;
      sub[as[i+1]]+=m-as[i]-1;
      vp.emplace_back(as[i],m);
      vp.emplace_back(-1,as[i+1]);
    }
  }

  vector<Int> cnt(m+1,0);
  vector< vector<Int> > G(m+1);
  for(auto p:vp){
    if(p.first==p.second) continue;
    cnt[p.first+1]++;
    G[p.second].emplace_back(p.first+1);
  }

  Int ans=res,num=cnt[0];
  // cout<<0<<":"<<res<<" "<<num<<endl;
  for(Int i=1;i<m;i++){
    // resolve i - 1
    res-=sub[i-1];
    for(Int l:G[i-1]){
      res-=(i-1)-l;
      num--;
    }
    // at i
    res+=num;
    num+=cnt[i];
    chmax(ans,res);
    // cout<<i<<":"<<res<<" "<<num<<endl;
  }

  Int sum=0;
  for(auto p:vp) sum+=p.second-max(p.first,0LL);
  cout<<sum-ans<<endl;
  return 0;
}
