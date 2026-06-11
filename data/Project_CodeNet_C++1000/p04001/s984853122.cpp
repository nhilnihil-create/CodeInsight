#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string str;
vector<string> formula;

int generate(string s, int now, int additions) {
  if (now == str.length()) {
    formula.push_back(s);
  }else{
    generate(s, now+1, additions);
    s.insert(s.begin()+now+additions, '+');
    generate(s, now+1, additions+1);
  }
  return 0;
}

ll evaluate(string s) {
  ll sum = 0;
  ll num = 0;
  int digit = 0;
  s.push_back('+');
  rep (i, s.length()) {
    if (s[i] == '+') {
      sum += num;
      num = 0;
      digit = 0;
    }else{
      num = num*10 + s[i] - '0';
      digit++;
    }
  }
  return sum;
}

int main() {
  cin >> str;
  generate(str, 1, 0);
  ll ans = 0;
  rep (i, formula.size()) {
    ans += evaluate(formula[i]);
  }
  cout << ans << endl;
  return 0;
}
