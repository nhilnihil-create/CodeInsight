#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int AC = max(A, C);
  int BD = min(B, D);
  if (AC < BD)
    cout << BD - AC << endl;
  else
    cout << 0 << endl;
  return 0;
}