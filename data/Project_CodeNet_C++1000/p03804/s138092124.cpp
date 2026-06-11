#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<M; i++) cin >> B[i];
  if (N<M) {
    cout << "No" << endl;
    return 0;
  }
  else {
    for (int y=0; y<N-M+1; y++) {
      for (int x=0; x<N-M+1; x++) {
        bool flag = true;
        for (int i=0; i<M; i++) {
          for (int j=0; j<M; j++) {
            if (A[i+y][j+x]!=B[i][j]) {
              flag = false;
              break;
            }
          }
          if (!flag) break;
        }
        if (flag) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}