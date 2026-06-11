#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int count = 0;
  string S;
  cin >> N >> S;
  vector<int> v(N);
  int ans = 0;

  for (int i = 0; i < N; i++) {
    count += S[i] == 'I' ? 1 : -1;
    v[i] = count;
  }

  for (int i = 0; i < N; i++) {
    ans = max(ans, v[i]);
  }

  cout << ans << endl;
}