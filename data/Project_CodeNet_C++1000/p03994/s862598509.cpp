#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int K;
  cin >> K;

  int N = S.size();
  rep(i, N) {
    if (S[i] == 'a') continue;
    int ops = 'z' - S[i] + 1;
    if (ops <= K) {
      S[i] = 'a';
      K -= ops;
      if (K == 0) break;
    }
  }
  if (K) {
    S[N - 1] += (K % 26);
  }
  cout << S << endl;
  return 0;
}
