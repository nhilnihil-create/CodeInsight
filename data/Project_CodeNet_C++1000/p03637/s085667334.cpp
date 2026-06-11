#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int A;
  map<int, int> mp;
  rep(i, N) {
    cin >> A;
    if (A % 4 == 0)
      mp[4]++;
    else if (A % 2 == 0)
      mp[2]++;
  }

  if (N / 2 <= mp[4] || N <= mp[2] + 2 * mp[4])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}