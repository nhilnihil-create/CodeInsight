#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i % 2 == 0) d.push_back(a);
    else d.push_front(a);
  }
  if (n % 2 == 1) reverse(all(d));
  for (int i = 0; i < n; i++) {
    cout << d[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}