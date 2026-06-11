#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  for (int i = 0; i <= N; ++i) {
    int p = i * M;
    for (int j = 0; j <= M; ++j) {
      int q = j * N;
      int ans = p + q - i * j * 2;
      if (ans == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
