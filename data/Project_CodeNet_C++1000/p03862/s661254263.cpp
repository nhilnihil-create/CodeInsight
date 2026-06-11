#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,x;
  int b,ans=0;
  vector<int> a,c;
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>b;
    a.push_back(b);
    if(i!=0){
      c.push_back(a[i-1]+a[i]);
    }
  }
  for(int i=0;i<c.size();i++){
    if(c[i]>x){
      if(c[i]-a[i+1]>x) ans+=a[i+1]+(c[i]-a[i+1]-x),c[i+1]-=a[i+1];
      else ans+=c[i]-x,c[i+1]-=c[i]-x;
    }
  }
  cout<<ans<<"\n";
}
      
