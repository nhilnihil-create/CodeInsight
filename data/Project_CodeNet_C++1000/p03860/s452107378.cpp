#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  string s[3];
  string ans="";
  rep(i,0,3) {
    cin >>s[i];
    ans.push_back(s[i][0]);
  }

  cout <<ans <<endl;
  return 0;
}
