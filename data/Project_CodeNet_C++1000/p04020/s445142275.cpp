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
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll area_sum = 0;
    while (i < N && A[i] != 0) {
      area_sum += A[i];
      i++;
    }
    ans += area_sum / 2;
  }
  cout << ans << endl;
  return 0;
}