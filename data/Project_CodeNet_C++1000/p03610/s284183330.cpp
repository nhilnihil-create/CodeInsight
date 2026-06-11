#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string s; cin >>s;
  rep(i,0,s.size()) {
    if (!(i%2)) cout <<s[i];
  }
  cout <<endl;
  return 0;
}
