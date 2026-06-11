#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  string S;
  cin >> S;
  int sz = S.size();
  vector<int> n(sz);
  for (int i = 0; i < sz; i++) {
    n[i] = S[i]-'0';
  }
  long long ans=0;
  for (int bit = 0; bit < (1 << (sz-1)); bit++) {
    vector<long long> f = {n[0]};
    long long fsz = 1, sum = 0;
    for (int i = 0; i < sz-1; i++) {
      if ((1<<i)&bit) {
        f[fsz-1] = f[fsz-1]*10 + n[i+1];
      }
      else {
        f.push_back(n[i+1]);
        fsz++;
      }
    }
    for (int i = 0; i < fsz; i++) {
      sum += f[i];
    }
    ans += sum; 
  }
  cout << ans << endl;
}