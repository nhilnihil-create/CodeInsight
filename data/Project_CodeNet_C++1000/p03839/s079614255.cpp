#include<bits/stdc++.h>
using namespace std;
long ans=0;
int main(){
  int n;cin>>n;
  int k;cin>>k;
  vector<long> a(n),plus(n+1,0),minus(n+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>0)ans+=a[i];
    plus[i+1]=plus[i];
    minus[i+1]=minus[i];
    if(a[i]>0)plus[i+1]+=a[i];
    else minus[i+1]+=a[i];
  }
  long p=1e15,m=-1e15;
  for(int i=0;i<n+1-k;i++){
    p=min(p,plus[i+k]-plus[i]);
    m=max(m,minus[i+k]-minus[i]);
  }
  ans-=min(abs(p),abs(m));
  cout<<ans<<endl;
}