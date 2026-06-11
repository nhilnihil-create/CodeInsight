#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m;cin>>n>>m;
  int64_t ans=n;
  if(2*n>=m){
    cout <<m/2<<endl;
    return 0;
  }
  else{
    m-=2*n;
    while(1){
      m-=4;
      if(m>=0)ans++;
      else break;
    }
  }
  cout <<ans<<endl;
}