#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  string s, t;
  cin >> n >> s;
  int l = 0;
  rep(i,n) {
    if(s[i]==')'&&l==0) t = '(' + t;
    else if(s[i]==')') l--;
    else if(s[i]=='(') l++;
    t += s[i];
  }
  while(l>0) {
    t += ')';
    l--;
  }
  cout << t << endl;
  return 0;
}