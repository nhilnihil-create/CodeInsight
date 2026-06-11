#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> a(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  double avg = (double) sum/N;
  avg = round(avg);
  int cost = 0;
  for (int i = 0; i < N; i++) {
    int dist = abs(a[i] - avg);
    cost += dist*dist;
  }
  cout << cost;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
