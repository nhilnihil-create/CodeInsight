#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s,t;
  cin >> s;
  t = "CODEFESTIVAL2016";
  int ans = 0;
  rep(i,16){
    if(s[i] != t[i]){
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
