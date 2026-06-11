#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;

int main(){
  ll hh,ww,ans=1e11,s[3];cin>>hh>>ww;
  REP(k,2){
    ll h=hh,w=ww;
    if(k) swap(h,w);
    for(ll i=1;i<w;i++){
      s[0]=h*i;
      if(!(h%2)||!((w-i)%2)) s[1]=s[2]=h*(w-i)/2;
      else{
        s[1]=min(h,w-i)*(max(h,w-i)/2);
        s[2]=h*w-s[0]-s[1];
      }
      ans=min(ans,max({s[0],s[1],s[2]})-min({s[0],s[1],s[2]}));
    }
  }
  cout<<ans<<endl;
}