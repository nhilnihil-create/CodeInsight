#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  int a[n], b[n];
  int c[m], d[m];
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, m) cin >> c[i] >> d[i];
  
  ll mi = 10000000000;
  
  int ans;
  rep(i, n){
    mi = 10000000000;
    rep(j, m){
      if((abs(a[i] - c[j]) + abs(b[i] - d[j])) < mi){
        mi = abs(a[i] - c[j]) + abs(b[i] - d[j]);
        ans = j + 1;
      }
    }
    cout << ans << endl;
  }
      

  return 0;
}