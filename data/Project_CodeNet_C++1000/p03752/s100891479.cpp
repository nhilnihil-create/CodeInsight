#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int64_t> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);    
  }
  int64_t ans = 10000000000000000;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<15> s(tmp);
    int64_t M = 0;
    int C = 0;
    int64_t H = 0;
    for (int i = 0; i < N; i++) {
      if (a.at(i) > M) {
        C++;
        M = a.at(i);
      }
      else if (s.test(i)) {
        C++;
        M++;
        H += (M - a.at(i));
      }
    }
    if (C == K) {
      ans = min(ans, H);
    }
  }
  cout << ans << endl;      
}