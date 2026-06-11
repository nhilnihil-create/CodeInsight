#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  vector<int> v(26, 0);
  rep(i, s.size()){
    int x = static_cast<int>(s[i]) - 97;
    ++v[x];
  }
  string ans = "None";
  ostringstream sout;
  rep(i, 26){
    if (v[i] == 0){
      sout << static_cast<char>(i + 97);
      ans = sout.str();
      break;
    }
  }
  cout << ans << endl;
  return 0;
}