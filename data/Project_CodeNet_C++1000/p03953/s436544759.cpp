#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> xs(n);
  for(Int i=0;i<n;i++) cin>>xs[i];

  Int m,k;
  cin>>m>>k;
  vector<Int> as(m);
  for(Int i=0;i<m;i++) cin>>as[i],as[i]--;

  vector<Int> id(n-1);
  iota(id.begin(),id.end(),0);

  vector<Int> ch(id);
  for(Int a:as) swap(ch[a-1],ch[a]);

  auto mg=
    [&](auto as,auto bs){
      auto cs(id);
      for(Int i=0;i+1<n;i++)
        cs[i]=as[bs[i]];
      return cs;
    };

  vector<Int> res(id);
  while(k){
    if(k&1) res=mg(res,ch);
    ch=mg(ch,ch);
    k>>=1;
  }

  vector<Int> ans(xs);
  for(Int i=0;i+1<n;i++) ans[i+1]=ans[i]+(xs[res[i]+1]-xs[res[i]]);

  for(Int i=0;i<n;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
