#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  string S, T; cin >> S >> T;
  int sl = S.length(), tl = T.length();
  int sn[sl+1]={}, tn[tl+1]={};
  rep(i,sl) sn[i+1] = sn[i]+(S[i]=='A' ? 1 : 2);
  rep(i,tl) tn[i+1] = tn[i]+(T[i]=='A' ? 1 : 2);

  int q; cin >> q;
  rep(i,q) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int sums = sn[b] - sn[a-1];
    int sumt = tn[d] - tn[c-1];
    string result = ((sums-sumt)%3==0) ? "YES" : "NO";
    // cout << sums << " " << sumt << endl;
    cout << result << endl;
  }
  return 0;
}