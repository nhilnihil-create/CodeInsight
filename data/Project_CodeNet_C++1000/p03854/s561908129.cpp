#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<string> ts = {"dream", "dreamer", "erase", "eraser"};
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  rep(i,(int)ts.size()) reverse(ts.at(i).begin(), ts.at(i).end());
  
  for (int i = 0; i < s.size();) {
    bool match = false;
    rep(j,(int)ts.size()) {
      if(s.substr(i, ts.at(j).size()) == ts.at(j)) {
        match = true;
        i += ts.at(j).size();
        break;
      }
    }
    
    if (!match) {
      cout << "NO" << endl;
      return 0;
    }
    
  }
  cout << "YES" << endl;
}
