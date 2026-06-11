#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  stack<char> stk;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l, r;
  l = r = 0;
  rep(i, n){
    char now = s.at(i);
    if(now == '(') stk.push(now);
    else{
      if(stk.empty()) l++;
      else stk.pop();
    }
  }
  r = stk.size();
  rep(i, l) cout << '(';
  cout << s;
  rep(i, r) cout << ')';
  cout << endl;
  return 0;
}