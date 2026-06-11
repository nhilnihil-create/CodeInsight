#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];  
  A.erase(unique(A.begin(), A.end()), A.end());
  int ans = 1;
  FOR(i, 2, A.size()) {
    if ((A[i - 2] < A[i - 1] && A[i - 1] > A[i]) ||
        (A[i - 2] > A[i - 1] && A[i - 1] < A[i])) {
      ans++;
      i++;
    }
  }
  cout << ans << endl;
}

