#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,m,ans;
  cin >> n >> m;
  if(n<=m/2){
    ans = n + (m-2*n)/4;
  }else{
    ans = m/2;
  }
  cout<<ans<<endl;
  return 0;
}
