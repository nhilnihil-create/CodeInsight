#include <bits/stdc++.h>
#include <vector>
#include <map>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, bool> paper;
  
  rep(i, n) {
    int a;
    cin >> a;
    paper[a] = !paper[a];
  }
  
  int ans = 0;
  for(auto x : paper) {
    if(x.second) ++ans;
  }
  
  cout << ans << endl;
  
  
  return 0;
}
