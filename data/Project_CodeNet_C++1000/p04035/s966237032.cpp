#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll L;
  cin >> L;
  ll a[N];
  for (int i = 0; i < N; i++) cin >> a[i];
  ll longest = -1;
  int point = -1;
  for (int i = 1; i < N; i++) {
    if (longest < a[i-1]+a[i]) {
      longest = a[i-1]+a[i];
      point = i;
    }
  }
  if (longest >= L) {
    cout << "Possible" << endl;
    for (int i = 1; i < point; i++) {
      cout << i << endl;
    }
    for (int i = N-1; i > point; i--) {
      cout << i << endl;
    }
    cout << point << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
