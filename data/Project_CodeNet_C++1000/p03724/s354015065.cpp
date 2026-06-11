#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> Nodes(N, 0);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    Nodes[a]++, Nodes[b]++;
  }
  int even = 0, odd = 0;
  REP(i, N) {
    if (Nodes[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
  if (odd != 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}