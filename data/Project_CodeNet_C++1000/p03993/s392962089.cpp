#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int a[N];
  int ans = 0;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) {
    if (a[a[i]-1] == i + 1) {
      ans++;
    }
  }
  cout << ans / 2 << endl;
  return 0;
}