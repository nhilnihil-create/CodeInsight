#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
  string S; cin >>S;
  reverse(S.begin(),S.end());
  string moji[4]={"dream","dreamer","erase","eraser"};
  rep(i,0,4) reverse(moji[i].begin(),moji[i].end());
  int cur_pos=0;
  while (cur_pos<(int)S.size()) {
    bool flag=false;
    rep(i,0,4) {
      int find_index=S.find(moji[i],cur_pos);
      if (find_index==cur_pos) {
        cur_pos=find_index+moji[i].size();
        flag=true;
        break;
      }
    }
    if (!flag) {
      cout <<"NO" <<endl;
      return 0;
    }
  }
  cout <<"YES" <<endl;
  return 0;
}
