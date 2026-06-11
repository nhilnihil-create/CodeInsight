#include <bits/stdc++.h>

using namespace std;

int solve() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<bool> visited(N);

  int current = 0;
  int count = 0;
  while (!visited[current]) {
    visited[current] = true;
    count++;
    current = a[current];
    if (current == 1) return count;
  }
  return -1;
}

int main() {
  cout << solve() << endl;
  return 0;
}
