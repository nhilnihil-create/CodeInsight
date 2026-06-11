#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int K, S;
  cin >> K >> S;
  int ans = 0;

  for(int x = 0; x <= K; x++) {
    for (int y = 0; y <= K; y++) {
      int z = S - x - y;
      if (0 <= z && z <= K) ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}