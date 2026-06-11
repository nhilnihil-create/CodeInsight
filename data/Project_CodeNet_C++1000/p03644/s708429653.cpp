#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  int ans=1;
  rep(i,10){
    if(ans*2<=n){
      ans*=2;
    }
  }
  cout << ans;
  return 0;
}