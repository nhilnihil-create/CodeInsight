#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,k;
  cin>>n>>k;
  long long ans=k;
  for(int i=1;i<n;i++)ans*=k-1;
  cout<<ans<<endl;
  return 0;
}