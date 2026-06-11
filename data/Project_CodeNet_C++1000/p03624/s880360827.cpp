#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;
  for (int i='a';i<='z';i++) {
    bool flag=false;
    for (int j=0;j<S.size();j++) {
      if (S[j]==char(i)) {
        flag=true;
        break;
      }
    }
    if (!flag) {
      cout <<char(i) <<endl;
      return 0;
    }
  }
  cout <<"None" <<endl;
  return 0;
}
