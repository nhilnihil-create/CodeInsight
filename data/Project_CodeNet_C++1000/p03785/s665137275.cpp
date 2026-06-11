#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int n,c,k; cin>>n>>c>>k;
  int t[n];
  rep(i,n) {
    cin >> t[i];
  }
  sort(t, t+n);


  int ans = 0;
  for (int i =0; i < n;) {
    ++ans;
    int start = i;
    while (i < n && t[i] - t[start] <= k && i - start < c) {
      ++i;
    }
  }

  cout << ans << endl;
  return 0;
}