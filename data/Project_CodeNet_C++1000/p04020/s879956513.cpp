#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll ans = 0, cnt = 0;
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    if(x == 0){
      ans += cnt/2;
      cnt = 0;
    }
    else cnt += x;
  }
  ans += cnt/2;
  cout << ans << endl;
}