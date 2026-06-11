#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

  stack<char> s;
  string ans = "";
  ll n; cin >> n;
  string st; cin >> st;
  for(ll i = 0; i < n; ++i){
    if(s.size() != 0 && s.top() == '(' && st[i] == ')'){
        s.pop();
    }else{
        s.push(st[i]);
    }
  }
  ll o = 0, z = 0;
  while(s.size()){
    if(s.top() == ')')z++;
    else o++;
    s.pop();
  }
  for(ll i = 0; i < z; ++i){
    ans.insert(0, "(");
  }
  ans += st;
  for(ll i = 0; i < o; ++i){
    ans += ")";
  }
  cout << ans;
  return 0;
}
