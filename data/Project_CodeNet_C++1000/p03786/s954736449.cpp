#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll N, S{}, ans{1};
  cin >> N;
  vector<ll> A(N);
  for (ll &a : A) cin >> a, S += a;
  sort(rbegin(A), rend(A));
  for (int i = 0; i < N - 1; ++i) {
    S -= A[i];
    if (A[i] <= 2 * S) ++ans;
    else break;
  }
  cout << ans << endl;
}
