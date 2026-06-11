#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N,K; cin >>N >>K;
  vector<bool> kirai(10);
  rep(i,0,K) {
    int D; cin >>D;
    kirai[D]=true;
  }
  while (true) {
    string check=to_string(N);
    bool flag=true;
    rep(i,0,10) {
      int result=check.find(to_string(i));
      if (kirai[i]==true && result!=-1) {
        flag=false;
        break;
      }
    }
    if (flag) break;
    N++;
  }
  cout <<N <<endl;
  return 0;
}
