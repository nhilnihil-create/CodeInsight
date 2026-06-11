#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
  cin >> n;
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    cnt += a & 1;
  }
  if (cnt & 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
