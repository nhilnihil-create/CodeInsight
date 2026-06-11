#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N, K;
  cin >> N >> K;
  vector<char> D(K);
  REP(i, K) cin >> D[i];
  for (int i = N;; i++) {
    string s = to_string(i);
    bool ok = true;
    REP(j, s.size()) REP(k, K) {
      if (s[j] == D[k]) ok = false;
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
}