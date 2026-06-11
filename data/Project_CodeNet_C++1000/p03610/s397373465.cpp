#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();
  string T;
  for (int i = 0; i < N; i += 2) {
    T += S[i];
  }
  cout << T << endl;
  return 0;
}