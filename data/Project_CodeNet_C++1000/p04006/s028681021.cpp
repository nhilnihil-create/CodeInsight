#include <bits/stdc++.h>
using namespace std;

#define INF 102030405060708090
#define inf 1020304050

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  vector<int> a(n);
  vector<int> b(n*2);
  for (int i=0;i<n;i++) cin >> a[i];

  for (int i=0;i<n;i++) {
    b[i] = a[i];
    b[n+i] = a[i];
  }

  vector<int> mins(n,inf);
  long long ans = INF;
  for (int i=0;i<n;i++) {
    long long kans = x*i;
    for (int j=0;j<n;j++) {
      mins[j] = min(mins[j],b[n+j-i]);
      kans += mins[j];
    }
    ans = min(ans,kans);
  }
  cout << ans << endl;
}