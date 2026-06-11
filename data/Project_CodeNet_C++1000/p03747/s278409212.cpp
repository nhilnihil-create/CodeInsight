#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,l,t;
  cin>>n>>l>>t;
  vector<Int> x(n),w(n);
  for(Int i=0;i<n;i++) cin>>x[i]>>w[i];

  vector<Int> ps;
  for(Int i=0;i<n;i++){
    if(w[i]==1) ps.emplace_back((x[i]+t)%l);
    if(w[i]==2) ps.emplace_back((x[i]-t%l+l)%l);    
  }
  sort(ps.begin(),ps.end());

  Int cnt=0;
  for(Int i=1;i<n;i++){
    if(w[i]==w[0]) continue;
    Int d=(w[0]==1?x[i]-x[0]:x[0]+(l-x[i]));
    if(t*2<d) continue;
    cnt+=1+((t*2-d)/l);    
  }
  if(w[0]==2) cnt=n-cnt%n;
  cnt%=n;
  
  Int pos=(w[0]==1?x[0]+t:x[0]-t%l+l)%l;
  Int p=  lower_bound(ps.begin(),ps.end(),pos)-ps.begin();
  Int q=--upper_bound(ps.begin(),ps.end(),pos)-ps.begin();

  Int idx=w[0]==1?q:p;
  vector<Int> ans(n);
  for(Int i=0;i<n;i++) ans[(cnt+i)%n]=ps[(idx+i)%n];

  //cout<<cnt<<" "<<idx<<endl;
  for(Int i=0;i<n;i++) cout<<ans[i]<<endl;
  return 0;
}
