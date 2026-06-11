#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int a[2*N-1]; rep(i,2*N-1) cin >> a[i];
  int l = 1, r = 2*N-1;
  while(l!=r) {
    int mid = (l+r+1)/2;
    bool lt[2*N-1] = {};
    rep(i,2*N-1) if (a[i]>=mid) lt[i] = true;
    bool ok = lt[0];
    // cout << l << "-" << mid << "-" << r << endl;
    // rep(i,2*N-1) cout << lt[i] << " "; cout << endl;
    rep(i,N-1) {
      // cout << lt[N-2-i] << "==" << lt[N-1-i] << " " << lt[N-1+i] << "==" << lt[N+i] << endl;
      if (lt[N-1+i]==lt[N+i]) { ok = lt[N-1+i]; break; }
      else if (lt[N-1-i]==lt[N-2-i]) { ok = lt[N-1-i]; break; }
    }
    if (ok) l = mid;
    else r = mid-1;
  }
  int result = l;
  cout << result << endl;
  return 0;
}