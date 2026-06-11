#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;
  vector<char> vec(S.size());
  rep(i,0,S.size()) vec[i]=S[i];
  while(true) {
    vec.pop_back();
    if (vec.size()%2) continue;
    else {
      int count=0;
      rep(i,0,vec.size()/2) {
        if (vec[i]==vec[vec.size()/2+i]) count++;
      }
      if (count==(int)(vec.size())/2) {
        cout <<vec.size() <<endl;
        break;
      }
    }
  }
  return 0;
}
