#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;

  string ans;
  rep(i, s.size()){
    if (i % 2 == 0){
      ans.push_back(s[i]);
    }
  }
  cout << ans << endl;
  return 0;
}