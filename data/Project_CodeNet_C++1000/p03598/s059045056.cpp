#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < N; i++){
    int x;
    cin >> x;
    ans+=2 * min(x, K - x);
  }
  cout << ans << endl;
}
