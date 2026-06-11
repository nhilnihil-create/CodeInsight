#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int k, s;
  cin >> k >> s;
  int cnt = 0;

  for(int x = 0; x <= k; x++) {
    for(int y = x; y <= k; y++) {
      for(int z = y; z <= k; z++) {
        if(x+y+z == s) {
          if(x == y && y == z) cnt++;
          else if(x != y && y != z && z != x) cnt += 6;
          else cnt += 3;
        }
      }
    }
  }
  cout << cnt << endl;
}