#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int n; cin >> n;
  int ans = 0,num = 0;
  if(n==1){
    cout << 1 << "\n";
    return 0;}

  for(int i = 1; i<=n; ++i){
    int cnt = 0;
    for(int j = i; j%2!=1; j/=2){
      //cout << j << "\n";
      ++cnt;
    }
    if(cnt > num){
      num = max(num,cnt);
      ans = i;
    }
  }
  cout << ans << "\n";
}