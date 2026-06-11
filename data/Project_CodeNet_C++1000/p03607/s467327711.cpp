#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int,int>cnt;
  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num;
    cnt[num]++;
  }
  int ans = 0;
  for(auto it : cnt) ans += (it.second % 2);
  cout << ans;
  return 0;
}