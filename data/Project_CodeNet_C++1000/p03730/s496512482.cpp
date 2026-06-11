#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  int A,B,C; cin >>A >>B >>C;
  string ans="NO";
  rep_eq(i,1,B) {
    if((A*i)%B==C) {
      ans="YES";
      break;
    }
  }
  cout <<ans <<endl;
}
