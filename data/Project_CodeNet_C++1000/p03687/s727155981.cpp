#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string t;
  cin >> t;
  char g;
  int ans = 100; 
  for(char g='a'; g<='z'; g++) {
    string s = t;
    int cnt = 0;
    bool ok = false;
    rep(i,s.size()) {
      if(s.at(i)==g) break;
      else if(i==s.size()-1) ok = true;
    }
    while (!ok) {
      rep(i,s.size()) {
        if(s.at(i)!=g) break;
        else if(i==s.size()-1) {
          ans = min(ans,cnt);
          ok = true;
        }
      }
      cnt++;
      string u;
      rep(i,s.size()-1) {
        if(s.at(i)==g||s.at(i+1)==g) u += g;
        else u += 'A';
      }
      s = u;
    }
  }
  cout << ans << endl;
}
