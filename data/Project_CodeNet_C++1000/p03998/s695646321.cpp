#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

char game(string sa, string sb, string sc, char p) {
  //cout << sa << " " << sb << " " << sc << endl;
  if(p == 'a') {
    if(sa.size() == 0) return 'A';
    else {
      char n = sa[0];
      sa.erase(sa.begin());
      return game(sa, sb, sc, n);
    }
  }
  if(p == 'b') {
    if(sb.size() == 0) return 'B';
    else {
      char n = sb[0];
      sb.erase(sb.begin());
      return game(sa, sb, sc, n);
    }
  }
  if(p == 'c') {
    if(sc.size() == 0) return 'C';
    else {
      char n = sc[0];
      sc.erase(sc.begin());
      return game(sa, sb, sc, n);
    }
  }
}

signed main() {
  string sa, sb, sc; cin >> sa >> sb >> sc;
  
  cout << game(sa, sb, sc, 'a') << endl;
}
