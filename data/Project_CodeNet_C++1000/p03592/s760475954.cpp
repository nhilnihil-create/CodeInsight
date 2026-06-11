#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (n); ++i)

using namespace std;
const string YES = "Yes";
const string NO = "No";

void solve(int N, int M, long K) {
  // greedy search
  rep(i, N)
    rep(j, M)
    if (i * M + j * N - i * j * 2 == K) {
      cout << YES << endl;
      return;
    }
  cout << NO << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  long K;
  cin >> K;

  solve(N, M, K);
  return 0;
}
