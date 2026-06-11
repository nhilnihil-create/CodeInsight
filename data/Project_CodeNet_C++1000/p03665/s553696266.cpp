#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int N, P;
vector<int> A;
unordered_map<int, int64_t> memo;

int64_t dfs(int idx, int par) {
  int key = idx * 2 + par;
  if (memo.count(key)) return memo[key];
  if (idx == N) {
    return (par == P) ? 1 : 0;
  }
  int64_t ret = dfs(idx + 1, par) + dfs(idx + 1, (par + A[idx]) % 2);
  return memo[key] = ret;
}

int main(void) {
  cin >> N >> P;
  A.resize(N);
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    A[i] = a % 2;
  }
  cout << dfs(0, 0) << endl;
  return 0;
}