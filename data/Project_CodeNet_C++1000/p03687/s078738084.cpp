#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;

  int ans = 1000;
  for(char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    string ss = s;
    bool flg = true;
    for(int i=0;i<ss.size();i++) {
      if(ss[i] != c) flg = false;
    }
    if(flg) {
      cout << 0 << endl;
      return 0;
    };
    while(ss.size() > 0) {
      bool flg = true;
      string next = "";
      for(int i=0;i<ss.size()-1;i++) {
        char next_c = ss[i] == c ? ss[i] : ss[i+1];
        if(next_c != c) flg = false;

        next.push_back(next_c);
      }
      ss = next;
      cnt++;
      if(flg) break;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
