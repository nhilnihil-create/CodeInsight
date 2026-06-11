#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string s; cin >>s;
  int temp1,temp2;
  for (int i=0;i<(int)s.size();i++) {
    if (s[i]=='A') {
      temp1=i;
      break;
    }
  }
  for (int i=s.size()-1;0<=i;i--) {
    if (s[i]=='Z') {
      temp2=i;
      break;
    }
  }
  cout <<temp2-temp1+1 <<endl;
  return 0;
}
