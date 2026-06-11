#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,k;
  cin >> n >> k;
  
  int x[n];
  rep(i,n) cin >> x[i];
  
  int ans = 0;
  rep(i,n){
    if(x[i] < k - x[i]){
      ans += x[i] * 2;
    }else{
      ans += (k -x[i]) * 2;
    }
  }
  
  cout << ans << endl;
}