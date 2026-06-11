#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  int K, T;
  cin >> K >> T;
  vector<int> a(T);
  for (int i=0; i<T; i++) cin >> a[i];
  sort(a.begin(), a.end());
  // 最大勢力がa[T-1]以外に存在するかどうか
  bool exist = false;
  for (int i=T-2; i>=0; i--) {
    if (a[i]==a[T-1]) {
      exist = true;
      break;
    }
  }
  if (exist) cout << 0 << endl;
  else {
    if (2*a[T-1]-1<=K) cout << 0 << endl;
    else cout << 2*a[T-1]-K-1 << endl;
  }
  return 0;
}