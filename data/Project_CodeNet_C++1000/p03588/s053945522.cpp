#include <bits/stdc++.h>
using namespace std;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main () {
  int N, M = 0, ans;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int A,B;
    cin >> A >> B;
    if (chmax(M,A)) ans = A+B;
  }
  cout << ans << endl;
}
    
    
