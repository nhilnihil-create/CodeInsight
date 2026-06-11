#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

int digit(int n) {
  int i=0;
  while(n > 0) {
    n /= 10;
    i++;
  }
  return i;
}

signed main() {
  int N, M, K; cin >> N >> M >> K;
  
  rep(i, N+1) rep(j, M+1) {
    if(N*j + M*i -2*i*j == K) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

}
