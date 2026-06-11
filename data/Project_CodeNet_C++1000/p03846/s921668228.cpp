#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a.at(i);
  sort(a.begin(), a.end());
  int f = 1;
  if(n & 1) {
    f = !a[0];
    for(int i = 1; i < n; i += 2)
      if(a[i] != a[i + 1])
        f = 0;
  } else
    for(int i = 0; i < n; i += 2)
      if(a[i] != a[i + 1])
        f = 0;
  if(f) {
    ll o = 1;
    for(int i = 0; i < n / 2; i++)
      o = o * 2 % MOD;
    cout << o << endl;
  } else
    cout << 0 << endl;
}