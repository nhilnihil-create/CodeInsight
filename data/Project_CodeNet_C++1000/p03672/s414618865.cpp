#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  string s;
  cin >> s;
  int N;
  N = s.size();
  int ans;
  rep(i,N-1) {
    if (i%2 == 0) {
      continue;
    } 
    int a = 1;
    rep(j,(i+1)/2) {
      if (s[j] != s[j+(i+1)/2]) {
        a = 0;
      }
    } 
    if (a == 1) {
      ans = i+1;
    }

  }
  cout << ans << endl;
  return 0;
}
