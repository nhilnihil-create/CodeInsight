#include <bits/stdc++.h>
using namespace std;

int main() {
  int x=0,N;
  int ans =0;
  string S;

  cin >> N >> S;
  for(int i=0;i<N;++i){
    if(S.at(i) == 'I'){
      x += 1;
    }else{
      x -= 1;
    }

    if(ans < x) ans = x;
  }
  cout << ans << endl;
  return 0;
}
