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
  ll N;
  cin >> N;
  vector<ll> T(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> T[i];
    sum += T[i];
  }
  ll M;
  cin >> M;
  vector<ll> P(M), X(M);
  for (int i = 0; i < M; i++) {
    cin >> P[i] >> X[i];
    P[i]--;
    cout << sum + X[i] - T[P[i]] << endl;
  }
  return 0;
}