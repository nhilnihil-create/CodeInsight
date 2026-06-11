#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> cnt(9);
  for (auto a : A) (a < 400) ? cnt.at(0) = 1 : (a < 800) ? cnt.at(1) = 1 :  (a < 1200) ? cnt.at(2) = 1 :  (a < 1600) ? cnt.at(3) = 1 :  (a < 2000) ? cnt.at(4) = 1 :  (a < 2400) ? cnt.at(5) = 1 :  (a < 2800) ? cnt.at(6) = 1 :  (a < 3200) ? cnt.at(7) = 1 : cnt.at(8)++;
  int sum = accumulate(cnt.begin(), cnt.end(), 0);
  if (cnt.at(8) == 0) return cout << sum << " " << sum << "\n", 0;
  sum = accumulate(cnt.begin(), cnt.begin() + 8, 0);
  if (sum) cout << sum << " " << sum + cnt.at(8) << "\n", 0;
  else cout << 1 << " " << cnt.at(8) << "\n";
}