#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  int k = a[0], cnt = 1, bo = 0;
  for (int i = 1; i < n; i++)
  {
    if ((a[i] < k && bo == 1) || (a[i] > k && bo == -1)) {
      cnt++; bo = 0;
    } 
    else {
      if (a[i] > k) bo = 1;
      if (a[i] < k) bo = -1;
    }
    k = a[i];
  }
  cout << cnt << endl;
  return 0;
}