#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

const int mod = 1000000007;

int fac(int N) {
  if(N < 0) return 0;
  if(N == 1 || N == 0) return 1;
  int n = 1;
  while(N>0) {
    n *= N;
    n %= mod;
    N--;
  }
  return n;
}

signed main() {
  int N, M; cin >> N >> M;
  
  if(abs(N-M) > 1) {
    cout << 0 << endl;
    return 0;
  }
  
  if(abs(N-M) == 0) cout << (fac(N)*fac(M)*2)%mod << endl;
  else cout << (fac(N)*fac(M))%mod << endl;

}