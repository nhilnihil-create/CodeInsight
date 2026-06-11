#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  bool can = false;
  for (int i=0; i<=N; i++) {
    for (int j=0; j<=M; j++) {
      if (i*(M-j)+(N-i)*j==K) {
        can = true;
        break;
      }
    }
    if (can) break;
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}