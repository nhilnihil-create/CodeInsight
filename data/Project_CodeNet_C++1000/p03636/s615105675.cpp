#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  string S;
  cin >> S;
  string answer;
  answer = S[0] + to_string(S.size() - 2) + S.back();
  cout << answer << endl;
  return 0;
}