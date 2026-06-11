#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int K, T;
  cin >> K >> T;
  int SUM_K = 0;
  int MAX_K = 0;
  rep(i, T) {
    int a;
    cin >> a;
    SUM_K += a;
    MAX_K = max(MAX_K, a);
  }
  SUM_K -= MAX_K;
  int answer = 0;
  answer = max(answer, MAX_K - SUM_K - 1);
  cout << answer << endl;
  return 0;
}
