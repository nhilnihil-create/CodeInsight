#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int n = s.size() - 1;
  long long ans = 0;
  for (int bit = 0; bit < (1<<n); bit++) {
    vector<long long> a;
    int m = 0;
    for (int i = 1; i <= n+1; i++) {
      if(bit&(1<<(n-i)) || i==n+1) {
        long long b = stoll(s.substr(m, i-m));
        a.push_back(b);
        m = i;
      }
    }
    for (long long x : a) ans += x;
  }
  cout << ans << endl;
}