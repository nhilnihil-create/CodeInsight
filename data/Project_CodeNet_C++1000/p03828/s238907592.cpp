#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long ans = 1;
  cin >> n;
  vector<long long>cnt(1001,0);
  for(int i = 2;i <= n;i++){
    int v = i;
    for (int p = 2;p <= sqrt(v);p++) {
      if (v%p != 0) continue;
      int num = 0;
      while (v%p == 0){
        num++;
        v /= p;
      }
      cnt[p] += num;
    }
    if(v != 0) cnt[v]++;
  }
  for(int i = 2;i < 1001;i++){
    if(cnt[i] == 0) continue;
    ans *= cnt[i]+1;
    ans %= 1000000000+7;
  }
  cout << ans << endl;
}
