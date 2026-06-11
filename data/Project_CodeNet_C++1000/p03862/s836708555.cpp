#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,x;cin>>N>>x;
  vector<long long>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  long long ans=0;
  for(int i=0;i<N-1;i++){
    if(a[i]+a[i+1]<=x)continue;
    ans+=a[i]+a[i+1]-x;
    if(a[i]>=x)a[i+1]=0;
    else a[i+1]-=a[i]+a[i+1]-x;
  }
  cout<<ans<<endl;
}