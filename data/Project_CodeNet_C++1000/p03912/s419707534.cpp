#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;
  int x[n];
  for (int i=0; i<n; i++) {
    cin>>x[i];
  }
  int same[(int)1e5+1];
  for (int i=0; i<1e5+1; i++) same[i] = 0;
  for (int i=0; i<n; i++) {
    ++same[x[i]];
  }
  int num_pairs[m];
  for (int i=0; i<m; i++) num_pairs[i] = 0;
  for (int i=0; i<1e5+1; i++) {
    num_pairs[i%m] += same[i] / 2;
  }
  int mods[m];
  for (int i=0; i<m; i++) mods[i] = 0;
  for (int i=0; i<n; i++) {
    ++mods[x[i]%m];
  }
  int cnt = 0;
  for (int i=0; i<=m/2; i++) {
    if (i == 0) {
      cnt += mods[0] / 2;
    } else if (m % 2 == 0 && i == m/2) {
      cnt += mods[m/2] / 2;
    } else {
      int l, s;
      if (mods[i] > mods[m-i]) {
        l = i;
        s = m - i;
      } else {
        l = m - i;
        s = i;
      }
      cnt += mods[s];
      cnt += min((mods[l] - mods[s]) / 2, num_pairs[l]);
    }
  }
  cout<<cnt<<endl;
}