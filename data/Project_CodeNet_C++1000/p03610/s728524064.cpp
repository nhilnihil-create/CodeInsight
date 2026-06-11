#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
int main() {
  string s;
  cin >> s;
  int n=s.size();
  string ans;
  rep(i,n) {
    if(i%2==0) ans+=s[i];
  }
  cout << ans << endl;
  return 0;
}
