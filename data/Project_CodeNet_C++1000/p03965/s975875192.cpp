#include <bits/stdc++.h>
using namespace std;

// 相手がパーを出せるときは自分もパーを出せるので全て相殺し、
// 余ったパーを相手のグーにぶつければよい。(最後から埋めていけば制約を満たせる。)
int main(){
  string hands;
  cin >> hands;

  int64_t ans= hands.size()/2;
  for(auto hand:hands){
    if(hand=='p'){ ans--; }
  }

  cout << ans << endl;
}