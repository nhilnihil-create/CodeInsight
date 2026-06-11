#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using P = pair<string, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
//#define DEBUG

int main() {
  string s;
  cin >> s;
 
  LL len = s.size();

  stack<P> exp;
  exp.push(make_pair<string, LL>(string() + s[0], 1LL));
  LL sum = 0;
  while (!exp.empty()) {
    auto current_exp = exp.top().first;
    auto current_depth = exp.top().second;
    #ifdef DEBUG
    //cout << current_exp << endl;
    if (current_depth > len) return -1;
    #endif
    exp.pop();
    if (current_depth == len) {
      LL exp_head = 0;
      while (current_exp.find('+', exp_head) != string::npos) {
        auto plus_pos = current_exp.find('+', exp_head);
        sum += stoll(current_exp.substr(exp_head, plus_pos - exp_head));
        exp_head = plus_pos + 1;
      }
      sum += stoll(current_exp.substr(exp_head, current_exp.size() - exp_head));
    } else {
      exp.push(make_pair<string, LL>(current_exp + "+" + s[current_depth], current_depth + 1));
      exp.push(make_pair<string, LL>(current_exp + s[current_depth], current_depth + 1));
      #ifdef DEBUG
      cout << current_exp + "+" + s[current_depth] << endl;
      cout << current_exp + s[current_depth] << endl;
      #endif
    }
  }
  cout << sum << endl;

  #ifdef DEBUG
  #endif
}

