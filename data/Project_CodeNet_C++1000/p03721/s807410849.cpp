#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  long long N, K;
  cin >> N >> K;

  vector<pair<long long, long long>> p(N);

  for (int i = 0; i < N; i++) {
    long long a;
    long long b;
    cin >> a >> b;
    p.at(i) = make_pair(a, b);
  }

  sort(p.begin(), p.end());

  long long tot = 0;
  for (int i = 0; i < N; i++) {
    long long a;
    long long b;
    tie(a, b) = p.at(i);
    tot += b;
    if (tot >= K) {
      cout << a << endl;
      break;
    }
  }
}