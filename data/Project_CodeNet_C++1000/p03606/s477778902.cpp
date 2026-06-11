#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N;
  int cnt = 0;
  cin >> N;
  rep(i, N) {
    int l,r;
    cin >> l >> r;
    cnt += r - l + 1;

  }
  cout << cnt;
}