#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int vminn(vector<int> v, int n) {
  sort(v.begin(), v.end());
  return v[n-1];
}

int main() {
  int Q, H, S, D, N; cin >> Q >> H >> S >> D >> N;
  
  long long ans = 0;
  
  int a = vminn({8*Q, 4*H, 2*S, D}, 1);
  while(N >= 2) {
    ans += a;
    N -= 2;
  }

  a = vminn({4*Q, 2*H, S}, 1);
  while(N >= 1) {
    ans += a;
    N -= 1;
  }

  a = vminn({2*Q, H}, 1);
  while(N >= 0.5) {
    ans += a;
    N -= 0.5;
  }

  while(N > 0) {
    ans += Q;
    N -= 0.25;
  }
  
  cout << ans << endl;
  
}
