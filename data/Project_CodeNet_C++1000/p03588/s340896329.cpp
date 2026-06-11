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
  vector<pair<ll, ll>> AB(N);
  ll a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    AB[i] = {a, b};
  }
  sort(AB.begin(), AB.end());
  if (AB[N - 1].second == 0) {
    cout << AB[N - 1].first << endl;
  } else {
    cout << AB[N - 1].first + AB[N - 1].second << endl;
  }
  return 0;
}