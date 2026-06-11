#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  rep(i,n){
    if(s[i] == 'S') ++a;
    if(s[i] == 'E') ++b;
    if(s[i] == 'N') ++c;
    if(s[i] == 'W') ++d;
  }
  bool flag = false;
  if(a > 0 && b > 0 && c > 0 && d > 0) flag = true;
  else if(a == 0 && b > 0 && c == 0 && d > 0) flag = true;
  else if(a > 0 && b == 0 && c > 0 && d == 0) flag = true;
  if(flag) puts("Yes");
  else puts("No");
  return 0;
}
