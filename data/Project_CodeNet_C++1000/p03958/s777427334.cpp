#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n,t;
  cin>>n>>t;
  int a[t];
  int ans;
  for(int i=0;i<t;i++) cin>>a[i];
  sort(a,a+t);
  reverse(a,a+t);
  
  ans=a[0];
  ans--;
  for(int i=1;i<t;i++){
    ans-=a[i];
  }
  if(ans<0) ans=0;
  cout<<ans<<endl;
}