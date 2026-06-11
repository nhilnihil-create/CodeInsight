#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int n, k , x, y;
  cin >> n >> k >> x >> y;
  if (n > k) {
    cout << x*k + y*(n-k) << endl;
    return 0;
  }
  cout << x*n << endl;

  return 0;
}