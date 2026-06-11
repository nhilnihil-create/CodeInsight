#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  stack<char> ans;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'B') ans.push(s[i]);
    else {
      if (!ans.empty()) ans.pop();
    }
  }

  int loop = ans.size();
  string answer = "";
  rep(i,loop) {
    char c = ans.top();
    answer += c;
    ans.pop();
  }
  reverse(answer.begin(), answer.end());
  cout << answer << endl;
  return 0;
}