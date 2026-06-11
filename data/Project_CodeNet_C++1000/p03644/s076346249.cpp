#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=1;
  int i=2;
  while(i<=n){
    ans=i;
    i*=2;
  }
  cout<<ans<<endl;
}
