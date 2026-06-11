#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  string s,t ;
  cin >> n >> s >> t;
  int l = 2 * n;
  rep(i,n) {
    string tt = t.substr(0,i+1);
    string ss = s.substr(n-i-1,i+1);
    if (ss == tt) l = min(l, 2 * n - i -1);
    //if (s.substr(n-i-i,i+1) == t.substr(0,i+1)) l = min(l, 2*n-i-1); 
  }
  cout << l << endl;
  return 0;
}