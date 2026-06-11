#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E>> F;
  int water = F, salt = 0;
  for (int i = 0; i <= F; i += 100*A) {
    for (int j = 0; i+j <= F; j += 100*B) {
      if (i+j == 0) continue;
      for (int k = 0; i+j+k <= F; k += C) {
        for (int l = 0; i+j+k+l <= F; l += D) {
          if (E*(i+j)/100 < k+l) continue;
          if (salt*(i+j+k+l) <= (k+l)*(water+salt)) {
            water = i+j;
            salt = k+l;
          }
        }
      }
    }
  }
  cout << water + salt << " " << salt << endl;
}
