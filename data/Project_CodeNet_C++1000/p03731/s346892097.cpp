#include <bits/stdc++.h>
using namespace std;
int main() {
  long long time = 0, N, last = 0, T, t;
  for (cin >> N >> T; N; N--) {
    cin >> t;
    time += T-max(0ll,last-t);
    last = t+T;
  }
  cout << time;
}