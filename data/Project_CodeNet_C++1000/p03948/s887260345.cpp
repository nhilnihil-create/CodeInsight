#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INT_INF 1000000000
#define DOUBLE_INF 1e18
#define MOD 1000000007
#define mod(x) ((x % MOD) + MOD) % MOD
#define MAX_N 100002

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
  int N, T, A[MAX_N];
  cin >> N >> T;
  int m = INT_INF, max_diff = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    m = min(m, A[i]);
    if (A[i] - m == max_diff) {
      ans++;
    } else if (A[i] - m > max_diff) {
      ans = 1;
      max_diff = A[i] - m;
    }
  }

  cout << ans << endl;

  return 0;
}
