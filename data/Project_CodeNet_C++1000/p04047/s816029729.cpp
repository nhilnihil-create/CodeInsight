#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  int a[2*n];
  for(int i=0;i<2*n;i++)
       cin>>a[i];
  int ans=0;
  sort(a,a+2*n);
  for(int i=0;i<2*n;i+=2)
  {
    ans+=min(a[i],a[i+1]);
    
  }
  cout<<ans;
  return 0;
}