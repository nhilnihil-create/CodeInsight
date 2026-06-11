#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,M;
  cin >> N >> M;
  int64_t ans;
  if(N<=M/2){
    ans=N;
    M-=N*2;
    ans+=M/4;
    cout << ans << endl;
  }else{
    ans=M/2;
    cout << ans << endl;
  }
  return 0;
}
