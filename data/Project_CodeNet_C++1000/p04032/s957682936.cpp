#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;

  if(s.size() == 2){
    if(s[0] == s[1]){
      cout << "1 2" << endl;
    }
    else{
      cout << "-1 -1" << endl;
    }
    return 0;
  }

  rep(i, s.size() - 2){
    if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) continue;
    cout << i+1 << " " << i+3 << endl;
    return 0;
  }
  cout << "-1 -1" << endl;
  return 0;
}