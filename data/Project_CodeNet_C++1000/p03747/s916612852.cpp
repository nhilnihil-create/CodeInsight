#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long N, L, T;
  cin >> N >> L >> T;
  vector<long> xs(N, 0), ws(N, 0);
  for (long i = 0; i < N; ++i) {
    cin >> xs[i] >> ws[i];
  }

  vector<long> last_poses(N, 0);
  long counter = 0;
  for (long i = 0; i < N; ++i) {
    if (ws[i] == 1) {
      last_poses[i] = (xs[i] + T) % L;
      counter -= (xs[i] + T) / L;
    } else {
      last_poses[i] = ((xs[i] - T) % L + L) % L;
      counter += (T - (xs[i] + 1) + L) / L;
    }
  }

  sort(last_poses.begin(), last_poses.end());
  counter = (counter % N + N) % N;

  vector<long> res(N, 0);
  for (long i = 0; i < N; ++i) {
    res[(i + counter) % N] = last_poses[i];
  }

  for (auto &e : res) {
    cout << e << endl;
  }
  return 0;
}