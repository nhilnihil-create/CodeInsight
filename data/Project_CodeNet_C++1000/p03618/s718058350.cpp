#include <iostream>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string A;
  cin >> A;
  int64_t N = A.size();
  unordered_map<char, int64_t> count;
  rep(i, N) { count[A[i]]++; }
  int64_t answer = 1 + N * (N - 1) / 2;
  for (char c = 'a'; c <= 'z'; ++c) {
    answer -= (count[c] * (count[c] - 1) / 2L);
  }
  cout << answer << endl;
  return 0;
}
