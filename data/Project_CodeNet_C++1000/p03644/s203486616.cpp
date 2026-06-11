#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int cnt = 0;
  int ans = 1;

  cin >> N;
  for(int i=1;i<=N;++i){
    int s = i;
    int t = 0;
    while(s % 2 == 0){
      t += 1;
      s /= 2;
    }
    if(t > cnt){
      cnt = t;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
