#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int s[N];
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s,s+N);
  if (sum % 10 != 0) {
    cout << sum << endl;
  } else {
    int mi = -1;
    for (int i = 0; i < N; i++) {
      if (s[i] % 10 != 0) {
        mi = i;
        break;
      }
    }
    if (mi == -1) {
      cout << 0 << endl;
    } else {
      cout << sum - s[mi] << endl;
    }
  }
  return 0;
}