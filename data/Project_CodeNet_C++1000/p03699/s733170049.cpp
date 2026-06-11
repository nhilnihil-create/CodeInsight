#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) cin >> S.at(i);
  int sum = accumulate(S.begin(), S.end(), 0L);
  vector<int> V;
  for (auto s : S) if (s % 10) V.push_back(s);
  if (V.size()) sort(V.begin(), V.end());
  if (sum % 10) return cout << sum << "\n", 0;
  if (V.size()) cout << sum - V.at(0) << "\n";
  else cout << 0 << "\n";
}