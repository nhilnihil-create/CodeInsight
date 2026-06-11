#include <iostream>
#include <vector>

using namespace std;

template <class T>
ostream& operator<<(ostream& os, vector<T> const& v) {
  for (int i = 0; i < v.size() - 1; i++) os << v[i] << ' ';
  if (!v.empty()) os << v.back();

  return os;
}

int main(void) {
  uint64_t K;
  cin >> K;

  constexpr uint64_t N = 50;
  vector<uint64_t> ans(N);
  for (auto& x : ans) x = (N - 1) + K / N;

  for (uint64_t i = 0; i < (K % N); i++) {
    ans[i] += N;
    for (uint64_t j = 0; j < N; j++) {
      if (i != j) ans[j]--;
    }
  }
  cout << N << endl;
  cout << ans << endl;

  return 0;
}