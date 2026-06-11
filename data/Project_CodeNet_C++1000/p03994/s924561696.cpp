#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG


signed main() {
  string s; cin >> s;
  int K; cin >> K;
  

  rep(i, s.size()) {
    if(s[i] != 'a' && 'z' - s[i] + 1 <= K) {
      K -= 'z' - s[i] + 1;
      s[i] = 'a';
    }
    if(K == 0) {
      cout << s << endl;
      return 0;
    }
  }
  
  if(K > 25) K %= 26;
  
  s[s.size()-1] += K;
  cout << s << endl;


}