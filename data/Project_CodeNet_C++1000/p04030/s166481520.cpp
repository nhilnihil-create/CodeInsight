#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1001001001;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main() {
string s,ans;
cin >> s;
rep(i,s.size()) {
  if (s[i] == 'B') {
    if (ans == "") continue;
    ans.pop_back();
    continue;
  }
  ans.push_back(s[i]);
}
cout << ans << endl;
    
return 0;
}
