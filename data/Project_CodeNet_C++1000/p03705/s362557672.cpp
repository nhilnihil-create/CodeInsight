#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, A, B; cin >> N >> A >> B;
  
  if(A > B || (N == 1 && A != B)) {
    cout << 0 << endl;
    return 0;
  }
  
  cout << (B*N-B+A)-(A*N-A+B)+1 << endl;
}
