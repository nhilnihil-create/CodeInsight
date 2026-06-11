#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  vector<queue<char>> vec_q(3);
  rep(i,0,3) {
    string S; cin >>S;
    rep(j,0,S.size()) {
      vec_q[i].push(S[j]);
    }
  }

  int cur=0;
  while(true) {
    if (vec_q[cur].empty()) break;
    char card=vec_q[cur].front();
    vec_q[cur].pop();
    if (card=='a') cur=0;
    else if (card=='b') cur=1;
    else cur=2;
  }

  if (cur==0) cout <<'A' <<endl;
  else if (cur==1) cout <<'B' <<endl;
  else cout <<'C' <<endl;

  return 0;
}
