#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,l,t;
  cin>>n>>l>>t;
  l*=2;
  t*=2;
  vector<Int> xs(n),ws(n);
  for(Int i=0;i<n;i++) cin>>xs[i]>>ws[i],xs[i]*=2;

  vector<Int> pos(n);
  for(Int i=0;i<n;i++){
    pos[i]=xs[i]+(ws[i]==1?1:l-1)*t;
    pos[i]%=l;
  }

  Int idx=-1;
  for(Int i=0;i<n;i++){
    if(ws[i]!=1) continue;
    idx=i;
    break;
  }

  if(idx<0){
    for(Int i=0;i<n;i++) cout<<pos[i]/2<<endl;
    return 0;
  }

  Int cur=idx;
  for(Int i=0;i<n;i++){
    if(ws[i]==1) continue;
    Int s=0;
    if(i<idx) s=(l-(xs[idx]-xs[i]))/2;
    else s=(xs[i]-xs[idx])/2;
    if(s>t) continue;
    cur+=1;
    cur+=(t-s)/(l/2);
    cur%=n;
  }
  // cout<<idx<<" "<<cur<<endl;

  vector<Int> qs;
  for(Int i=0;i<n;i++){
    qs.emplace_back(pos[i]);
    qs.emplace_back(pos[i]+l);
  }
  sort(qs.begin(),qs.end());

  vector<Int> ans(n);
  for(Int i=0;i<n;i++){
    if(qs[i]!=pos[idx]) continue;
    if(qs[i]==qs[i+1]) continue;

    for(Int j=0;j<n;j++)
      ans[(cur+j)%n]=qs[i+j]%l;
    break;
  }
  for(Int i=0;i<n;i++) cout<<ans[i]/2<<endl;
  return 0;
}
