#include <iostream>
using namespace std;

int main () {
  int A, B, C;
  cin >> A >> B >> C;
  int ans = 0;
  while (1) {
    if (A % 2 != 0 || B % 2 != 0 || C % 2 != 0) break;
    int halfA = A/2;
    int halfB = B/2;
    int halfC = C/2;
    A = halfB + halfC;
    B = halfC + halfA;
    C = halfA + halfB;
    ans++;
    if (A == B && B == C) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}