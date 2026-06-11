#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int l[n],r[n];
  rep(i,n) cin >> l[i] >> r[i];
  
  ll ans = 0;
  rep(i,n){
    ans += r[i] - l[i] + 1;
  }
  
  cout << ans << endl;
  
  
}