#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a.at(i) >> b.at(i);
  
  long long ans = 0;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for(int i = 0; i < n; i++){
    a.at(i) += ans;
    long long cnt = (a.at(i) + b.at(i) - 1) / b.at(i);
    ans += b.at(i) * cnt - a.at(i);
  }
  
  cout << ans << endl;
}