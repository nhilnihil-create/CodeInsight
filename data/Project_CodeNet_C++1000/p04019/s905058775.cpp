#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  //int N; cin >> N;
  string S; cin >> S;
  
  int n=0, w=0, s=0, e=0;
  
  rep(i, S.size()) {
    if(S[i] == 'N') n=1;
    if(S[i] == 'W') w=1;
    if(S[i] == 'S') s=1;
    if(S[i] == 'E') e=1;
  }
  if((n*s==1||n+s==0) && (w*e==1||w+e==0)) cout << "Yes" << endl;
  else cout << "No" << endl;
    
}