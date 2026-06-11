#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string s;
  cin >> s;

  vector <int> ans;
  int N = s.length();
  rep(i,N){
    if (s[i] == '0') ans.push_back(0);
    else if (s[i] == '1') ans.push_back(1);
    else if (s[i] == 'B' && ans.size() != 0) ans.pop_back();
  }
  rep(i,ans.size()) cout << ans[i];
}
