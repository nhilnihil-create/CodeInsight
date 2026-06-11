#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int a[200000];
  long long int ans=1000000000000000;
  int n,b;
  int p;
  cin>>n;
  cin>>b;
  a[0]=b;
  for(int i=1;i<n;i++){
    cin>>b;
    a[i]=a[i-1]+b;
  }
  for(int i=0;i<n-1;i++){
    long long int d=a[n-1]-a[i];
    ans=min(ans,abs(a[i]-d));
  }
  cout<<ans<<endl;
  
  return 0;
}
