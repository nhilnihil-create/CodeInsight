#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int i=a;i<b;++i)

int main() {
  int N;
  int cnt = 0;

  cin >> N;

  int max_cnt = -1;
  int ans = -1;

  rep(1, N+1) {
    int cnt = 0;
    int y = i;

    while (y%2 == 0) {
      y /= 2;
      ++cnt;
    }

    if (max_cnt < cnt) {
      max_cnt = cnt;
      ans = i;
    }
  }

  cout << ans << endl;

  return 0;
}