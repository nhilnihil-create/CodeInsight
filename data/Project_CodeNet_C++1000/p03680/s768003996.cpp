#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(i, n) {
    cin >> a[i + 1];
  }

  int i = 1;
  int count = 0;
  while (count < n + 1) {
    if (i == 2) {
      break;
    }
    count++;
    i = a[i];
  }

  if (i == 2) {
    cout << count << endl;
  } else {
    cout << -1 << endl;
  }
  
  return 0;
}