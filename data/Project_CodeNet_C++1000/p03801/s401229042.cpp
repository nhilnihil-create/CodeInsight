#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  using P = pair<Int, Int>;
  vector<P> vp;
  Int tmp=0;
  for(Int i=0;i<n;i++){
    if(tmp<as[i]){
      vp.emplace_back(i,tmp);
      tmp=as[i];
    }
  }
  vector<Int> bs(as);
  sort(bs.begin(),bs.end());
  vector<Int> sm(n+1,0);
  for(Int i=0;i<n;i++) sm[i+1]=sm[i]+bs[i];

  Int m=vp.size();
  vector<Int> res(m+1,0);
  for(Int i=0;i<m;i++){
    Int k=lower_bound(bs.begin(),bs.end(),vp[i].second)-bs.begin();
    //cout<<vp[i].second<<" "<<k<<":"<<bs[k]<<endl;
    res[i]=(sm[n]-sm[k])-(n-k)*vp[i].second;
    //cout<<i<<" "<<res[i]<<endl;
  }

  for(Int i=0;i<m;i++)
    res[i]-=res[i+1];

  vector<Int> ans(n);
  for(Int i=0;i<m;i++)
    ans[vp[i].first]=res[i];

  for(Int i=0;i<n;i++) cout<<ans[i]<<endl;
  return 0;
}
