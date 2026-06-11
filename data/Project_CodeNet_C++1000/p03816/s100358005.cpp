#include<bits/stdc++.h>
using namespace std;
int cnt[100005];
int main(){
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x; cnt[x]++;
  }
  int res = 0, say = 0;
  for (int i = 1; i <= 100000; i++) {
    if (cnt[i] == 0) continue;
    res += cnt[i] - 1;
    say++;
  }
  cout << (res % 2 == 0 ? say : say - 1) << endl;
  return 0;
}