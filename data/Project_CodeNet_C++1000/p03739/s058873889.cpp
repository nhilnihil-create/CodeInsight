#include <bits/stdc++.h>
using namespace std;

long long int f(long long int sum, vector<int>& a, long long int n, long long int ans){
  int isum = sum;
  for (int i = 1; i < n; i++) {
    int temp = isum;
    isum += a[i];
    if (temp > 0) {
      if (isum >= 0) {
        ans += (1 + isum);
        isum = -1;
      }
    }
    else if(temp < 0) {
      if (isum <= 0) {
        ans += (1 + abs(isum));
        isum = 1;
      }
    }
  }
  return ans;
}
void solve() {
  long long int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0 ; i < n; i++) {
    cin >> a[i];
  }
  long long int p = 1;
  long long int ne = -1;
  long long int pans = 1;
  long long int nans = 1;
  if(a[0] > 0) {
    p = a[0];
    nans = a[0] + 1;
    pans--;
  }
  else if (a[0] < 0) {
    ne = a[0];
    nans--;
    pans = abs(a[0]) + 1;
  }
  cout << min(f(p, a, n, pans), f(ne, a, n, nans));
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
