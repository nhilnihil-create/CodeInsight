#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  map<int, int> mp;
  mp[A]++;
  mp[B]++;
  mp[C]++;
  if (mp[5] == 2 && mp[7] == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}