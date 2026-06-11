#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  set<char> st;
  vector<int> board(26);
  for(int i = 0; i < (int)s.size(); i++) {
    if(st.count(s[i]) == 0) {
      st.insert(s[i]);
      board[s[i] - 'a'] = 1;
    }
    if((int)st.size() == 26) {
      cout << "None" << endl;
      return 0;
    }
  }
  string ans = "";
  rep(i, 26) {
    if(board[i] == 0) {
      ans = i + 'a';
      cout << ans << endl;
      return 0;
    }
  }
}