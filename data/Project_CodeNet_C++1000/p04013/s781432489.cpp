#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ll N, A, x, ans{};
  cin >> N >> A;
  vector<map<int,ll>> V(A*N+51);
  V[0][0] = 1;
  while(cin >> x)
    for (int i = A*N; i >= x; --i)
      for (auto &p: V[i-x]) V[i][p.first+1] += p.second;
  for (int i = 1; i <= N; ++i) ans += V[i*A][i];
  cout << ans << endl;
}
