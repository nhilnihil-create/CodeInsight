#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  int ans1 = 0;
  int ans2 = 0;
  long double mx = -1.0;
  for (int i = 0; i <= 60; i++) {
    for (int j = 0; j <= 60; j++) {
      if ((A * i * 100) + (B * j * 100) <= F && (A * i * 100) + (B * j * 100) != 0) {
        
      } else {
        continue;
      }
      for (int k = 0; k <= 2500; k++) {
        for (int l = 0; l <= 2500; l++) {
          if ((A*i*100) + (B*j*100) + (C*k) + (D*l) <= F && ((A*i)+(B*j)) * E >= (C*k) + (D*l)) {
            if ((long double)((C*k) + (D*l)) / (long double)((A*i*100) + (B*j*100) + (C*k) + (D*l)) > mx) {
              ans1 = (A*i*100) + (B*j*100) + (C*k) + (D*l);
              ans2 = (C*k) + (D*l);
              mx = (long double)((C*k) + (D*l)) / (long double)((A*i*100) + (B*j*100) + (C*k) + (D*l));
            }
          }
        }
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}