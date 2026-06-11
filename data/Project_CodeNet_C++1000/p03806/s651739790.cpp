#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)
using P=pair<int,int>;

int main(){
  int n,x,y;
  cin>>n>>x>>y;
  int a[n];
  int b[n];
  int c[n];
  rep(i,0,n){
    cin>>a[i]>>b[i]>>c[i];
  }
  P before[1<<(n/2)];
  rep(i,0,1<<(n/2)){
    int d=0;
    int e=0;
    int f=0;
    rep(j,0,n/2){
      if(1 & i>>j){
        d+=a[j];
        e+=b[j];
        f+=c[j];
      }
    }
    before[i]=P(e*x-d*y,f);
  }
  sort(before,before+(1<<(n/2)));
  
  int ans=114514;
  rep(i,0,1<<(n-n/2)){
    int d=0;
    int e=0;
    int f=0;
    rep(j,0,n-n/2){
      if(1 & i>>j){
        d+=a[n/2+j];
        e+=b[n/2+j];
        f+=c[n/2+j];
      }
    }
    if(f!=0){
      int g=lower_bound(before,before+(1<<(n/2)),P(d*y-e*x,0))-before;
      if(g!=1<<(n/2) && before[g].first==d*y-e*x){
        ans=min(ans,f+before[g].second);
      }
    }
    else{
      int g=upper_bound(before,before+(1<<(n/2)),P(d*y-e*x,0))-before;
      if(g!=1<<(n/2) && before[g].first==d*y-e*x){
        ans=min(ans,f+before[g].second);
      }
    }
  }
  if(ans==114514){
    cout<<-1<<endl;
  }
  else{
    cout<<ans<<endl;
  }
}