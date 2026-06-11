#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, i;
  cin >> N;
  vector<int> a(3 * N);
  for (i = 0; i < 3 * N; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  int64_t M = 0;
  for (i = 0; i < N; i++) M += a.at(N + 2 * i);
  
  cout << M << endl;
}
