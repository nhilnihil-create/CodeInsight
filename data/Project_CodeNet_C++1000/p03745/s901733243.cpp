#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int n; cin>>n;
  int a[n];
  rep(i, n) {
    cin >> a[i];
  }

  string mode = "init";
  int ans = 1;

  for(int i = 0; i < n-1; i++){
    if (mode == "init") {
      if(a[i] < a[i+1]) {
        mode = "plus";
      } else if (a[i] > a[i+1]) {
        mode = "minus";
      }
    // 単調非減少
    } else if (mode == "plus") {
      if(a[i] > a[i+1]) {
        ans++;
        mode = "init";
      }
    // 単調非増加
    } else if (mode == "minus") {
      if(a[i] < a[i+1]) {
        ans++;
        mode = "init";
      }
    }
  }
  cout << ans << endl;
  return 0;
}