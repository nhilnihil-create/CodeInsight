#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  int A, B, C, D, E, F, maxW{}, maxS{};
  double m{};
  cin >> A >> B >> C >> D >> E >> F;
  for (int a = 0; a < F; a += 100*A) {
    for (int b = 0; a + b < F; b += 100*B) {
      for (int c = 0; a + b + c <= F; c += C) {
        if (100.*c/(a+b+c) > E) break;
        for (int d = 0; a + b + c + d <= F; d += D) {
          auto co = 100.*(c+d)/(a+b+c+d);
          if (co > m) {
            if (c+d > (a+b)/100*E) break;
            m = co;
            maxW = a+b+c+d;
            maxS = c+d;
          }
        }
      }
    }
  }
  if (!maxW) maxW = 100*A;
  cout << maxW << " " << maxS << endl;
}
