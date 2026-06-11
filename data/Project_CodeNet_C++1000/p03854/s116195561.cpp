#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;
  string check[4]={"dream","dreamer","erase","eraser"};
  reverse(S.begin(),S.end());
  rep(i,0,4) {
    reverse(check[i].begin(),check[i].end());
  }
  int cur=0;
  while (cur<(int)S.size()) {
    bool flag=false;
    rep(i,0,4) {
      int find_pos=S.find(check[i],cur);
      if (cur==find_pos) {
        flag=true;
        cur=find_pos+check[i].size();
        break;
      }
    }
    if (!flag) {cout <<"NO" <<endl; return 0;}
  }
  cout <<"YES" <<endl;
  return 0;
}
