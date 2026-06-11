#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(A.rbegin(), A.rend());

  long long W = 0, H = 0;
  for(int i = 1; i < N; i++) {
    if(A[i-1] == A[i]) {
      if(!W) {
        W = A[i];
        // cout << "W: " << W << endl;
        i++;
      }
      else if(!H) {
        H = A[i];
        // cout << "H: " << H << endl;
        break;
      }
    }
  }

  if(W && H) {
    cout << W * H << endl;
  }
  else {
    cout << 0 << endl;
  }

  return 0;
}
