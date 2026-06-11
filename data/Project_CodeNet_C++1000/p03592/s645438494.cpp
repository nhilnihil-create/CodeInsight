#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  ll area = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i * (M - j) + j * (N - i) == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}