#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  rep(i,0,s.size()-1){
    if(s[i] == s[i+1]){
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }
    if(i == s.size()-2) continue;
    if(s[i] == s[i+2]){
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
