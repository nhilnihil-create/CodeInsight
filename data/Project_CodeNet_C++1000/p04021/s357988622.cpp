#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> input(n);
  for(int i=0;i<n;i++) cin >> input[i];
  vector<int> a = input;
  sort(a.begin(), a.end());
  map<int, int> b;
  for(int i=0;i<n;i++) {
    if(i % 2 == 0) b[a[i]] = 0;
    else b[a[i]] = 1;
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(i % 2 == 1 && b[input[i]] == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
