#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;

  int ans=0;
  char check=S[0];

  rep(i,1,S.size()) {
    if (check!=S[i]) {
      ans++;
      check=S[i];
    }
  }

  cout <<ans <<endl;
  return 0;
}
