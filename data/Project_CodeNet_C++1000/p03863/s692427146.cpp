#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();
  if (S[0] == S[N - 1]) {
    if (N % 2)
      cout << "Second" << endl;
    else
      cout << "First" << endl;
  } else {
    if (N % 2)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}