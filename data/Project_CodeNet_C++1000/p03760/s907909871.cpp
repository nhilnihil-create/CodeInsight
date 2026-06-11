#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  string O,E; cin >>O >>E;
  rep(i,0,O.size()-1) {
    cout <<O[i] <<E[i];
  }
  if (O.size()==E.size()) cout <<O[O.size()-1] <<E[E.size()-1];
  else cout <<O[O.size()-1];
  cout <<endl;
  return 0;
}
