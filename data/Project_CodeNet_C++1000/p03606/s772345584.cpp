#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int a[N],b[N];
  
  for(int i=0;i<N;i++) {
    cin>>a[i]>>b[i];
  }
  
  int ans=0;
  for(int i=0;i<N;i++) {
    ans+=b[i]-a[i]+1;
  }
  
  cout<<ans<<endl;
  return 0;
}
