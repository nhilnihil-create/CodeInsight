#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using P = pair<string, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
//#define DEBUG

LL f(const string &s_orig, const string &&s_exp, const LL depth) {
  #ifdef DEBUG
  cout << s_exp << endl;
  #endif
  if (depth == s_orig.size()) {
    LL sum = 0;
    LL head = 0;
    while (s_exp.find('+', head) != string::npos) {
      auto plus_pos = s_exp.find('+', head);
      sum += stoll(s_exp.substr(head, plus_pos - head));
      head = plus_pos + 1;
    }
    sum += stoll(s_exp.substr(head, s_exp.size() - head));
    return sum;
  } else {
    return f(s_orig, s_exp + "+" + s_orig[depth], depth + 1)
           + f(s_orig, s_exp + s_orig[depth], depth + 1);
  }
}


int main() {
  string s;
  cin >> s;
 
  cout << f(s, string("") + s[0], 1) << endl;

  #ifdef DEBUG
  #endif
}

