#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  double a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  
  double res=0;
  double ans=0;
  rep(i,31)rep(j,31){
    double p=min(f-100*(a*i+b*j),e*(a*i+b*j));
    if(p<0) continue;
 
    double q=0;
    rep(k,int(p/c)+1){
      q=max(c*k+d*(int((p-c*k)/d)),q);
    }
    if(ans<q/(100*(a*i+b*j)+q)){
      res=100*(a*i+b*j)+q;
      ans=q/(100*(a*i+b*j)+q);
    }
  }
  if(res!=0) cout<<res<<" "<<res*ans<<endl;
  else cout<<100*a<<" "<<0<<endl;
}
