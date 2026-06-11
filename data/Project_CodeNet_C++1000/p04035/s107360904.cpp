#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main() {
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  bool yes = false;
  int knot = -1;
  for(int i=0;i<n-1;i++) {
    if(a[i] + a[i+1] >= l) {
      yes = true;
      knot = i+1;
      break;
    }
  }
  if(yes) {
    cout << "Possible" << endl;
  }
  else {
    cout << "Impossible" << endl;
    return 0;
  }
  for(int i=1;i<knot;i++) cout << i << endl;
  for(int i=n-1;i>knot;i--) cout << i << endl;
  cout << knot << endl;
  return 0;
}
