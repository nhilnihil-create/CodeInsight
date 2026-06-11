#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int n;cin>>n;
  int ans=0;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=0;i<n-1;i++){
    int a=min(v[i],v[i+1]);
    if((v[i]-a)&1)a--;
    if(a<0)a=0;
    ans+=a;
    v[i]-=a;v[i+1]-=a;
    ans+=v[i]/2;
  }
  ans+=v[n-1]/2;
  cout<<ans<<endl;
}

