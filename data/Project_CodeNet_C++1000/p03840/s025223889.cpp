#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int i, o, j, l, trash;
  cin >> i >> o >> trash >> j >> l >> trash >> trash;
  
  long long ans1 = o, ans2 = o;
  o = 0;
  
  ans1 += i / 2 * 2;
  ans1 += j / 2 * 2;
  ans1 += l / 2 * 2;
  
  if (i > 0 && j > 0 && l > 0) {
    ans2 += 3;
    i--;
    j--;
    l--;
  }
  ans2 += i / 2 * 2;
  ans2 += j / 2 * 2;
  ans2 += l / 2 * 2;
  
  cout << max(ans1, ans2) << '\n';
}