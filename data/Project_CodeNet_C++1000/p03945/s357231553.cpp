#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
  string S; cin >>S;
  char temp=S[0];
  int Ans=0;
  rep(i,1,S.size()) {
    if (temp!=S[i]) {
      Ans++;
      temp=S[i];
    }
  }
  cout <<Ans <<endl;
  return 0;
}
