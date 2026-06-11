#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
//#define DEBUG

int main() {
  string s;
  cin >> s;
 
  LL len = s.size();
  LL n = (1u << (len - 1));

  LL sum = 0u;
  rep(i, n) {
    string exp = "";
    rep (j, len - 1) {
      exp += s[j]; 
      if (i & (1u << j)) {
        exp += '+';
      }
    }
    exp += s[len - 1];

    LL current_head = 0;
    while (exp.find('+', current_head) != string::npos) {
      LL end = exp.find('+', current_head);
      sum += stoll(exp.substr(current_head, end - current_head));
      current_head = end + 1;
    }
    sum += stoll(exp.substr(current_head, exp.size() - current_head));
    #ifdef DEBUG
    cout << exp << endl;
    cout << sum << endl;
    #endif

  }
  cout << sum << endl;
  
  
  #ifdef DEBUG
  #endif
}

