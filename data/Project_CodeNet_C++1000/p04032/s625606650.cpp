#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  bool exist1=false, exist2=false;
  int ans1, ans2;
  for (int i=0; i<s.size()-1; i++) {
    if (s[i]==s[i+1]) {
      ans1=i+1, ans2=i+2;
      exist1 = true;
      break;
    }
  }
  for (int i=0; i<s.size()-2; i++) {
    if (s[i]!=s[i+1]&&s[i+1]!=s[i+2]&&s[i]==s[i+2]) {
      ans1=i+1, ans2=i+3;
      exist2 = true;
      break;
    }
  }
  if (exist1||exist2) cout << ans1 << " " <<  ans2 << endl;
  else cout << -1 << " " << -1 << endl;
}