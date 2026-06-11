#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string s; cin >>s;
  bool jouken1=!(s.size()%2);
  bool jouken2=(s[0]==s[s.size()-1]);
  if (jouken1!=jouken2) cout <<"Second" <<endl;
  else cout <<"First" <<endl;
  return 0;
}
