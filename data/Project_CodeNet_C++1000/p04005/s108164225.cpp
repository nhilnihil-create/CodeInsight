#include <bits/stdc++.h>
using namespace std;

#define int long long
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}

signed main(){
  int a,b,c;cin>>a>>b>>c;
  int ans=1e18;
  if(c>1)chmin(ans,a*b*((c+1)/2-c/2));
  if(a>1)chmin(ans,b*c*((a+1)/2-a/2));
  if(b>1)chmin(ans,c*a*((b+1)/2-b/2));
  cout<<ans<<endl;
}
