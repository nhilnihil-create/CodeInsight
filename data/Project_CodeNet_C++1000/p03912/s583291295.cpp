#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> xs(n);
  for(Int i=0;i<n;i++) cin>>xs[i];

  vector<Int> grp(m,0);
  for(Int x:xs) grp[x%m]++;

  map<Int, Int> cnt;
  for(Int x:xs) cnt[x]++;
  vector<Int> prs(m,0);
  for(auto p:cnt)
    prs[p.first%m]+=p.second/2;

  Int ans=grp[0]/2;
  if(m%2==0) ans+=grp[m/2]/2;

  for(Int i=1;i<m-i;i++){
    Int j=m-i;
    Int res=min(grp[i],grp[j]);
    ans+=res;
    grp[i]-=res;
    grp[j]-=res;
    //cout<<res<<":"<<grp[i]<<" "<<prs[i]<<" "<<grp[j]<<" "<<prs[j]<<endl;
    ans+=min(grp[i]/2,prs[i]);
    ans+=min(grp[j]/2,prs[j]);
  }

  cout<<ans<<endl;
  return 0;
}
