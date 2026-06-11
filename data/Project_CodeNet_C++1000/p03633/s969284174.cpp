#include <bits/stdc++.h>
using namespace std;

long long LCM (long long a, long long b) {
  long long a2 = a, b2 = b;
  long long r;
  while(max(a,b)%min(a,b) != 0) {
    r = max(a,b)%min(a,b);
    (a > b ? a : b) = r;
  }
  return a2/min(a,b)*b2;
}

int main() {
  int N;
  cin >> N;
  vector<long long> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  long long share = T.at(0);
  for (int i = 1; i < N; i++) {
    share = LCM(share, T.at(i));
  }
  cout << share << endl;
}