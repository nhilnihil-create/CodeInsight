#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t n,m;
  cin >> n >> m;
  int64_t ans=0;
  if(n*2>=m){
    cout << m/2;
    return 0;
  }
  ans+=n;
  m-=2*n;
  ans+=m/4;
  cout << ans;
}