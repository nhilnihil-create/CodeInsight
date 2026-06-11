#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p.begin(), p.end());
  for (int i = 1; i <= N; i++) {
    cout << N * i + p[i - 1].second << " ";
  }
  cout << endl;
  for (int i = 1; i <= N; i++) {
    cout << N * (N - i + 1) << " ";
  }
  cout << endl;
}