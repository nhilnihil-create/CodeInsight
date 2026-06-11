#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  vector<int> in(3);
  rep(i, 3) cin >> in[i];
  sort(in.begin(), in.end());
  if(in[0]==5 && in[1]==5 && in[2]==7) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
