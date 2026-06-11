#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  string S;
  cin >> S;
  int N = S.size();
  int p_num = 0;
  rep(i, N) {
    if (S[i] == 'p') p_num++;
  }
  int answer = N / 2 - p_num;
  cout << answer << endl;
  return 0;
}
