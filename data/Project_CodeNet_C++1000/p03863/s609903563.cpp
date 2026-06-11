#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string s; cin >>s;
  if (s.size()%2) {
    if (s[0]==s[s.size()-1]) cout <<"Second" <<endl;
    else cout <<"First" <<endl;
  } else {
    if (s[0]==s[s.size()-1]) cout <<"First" <<endl;
    else cout <<"Second" <<endl;
  }
  return 0;
}
