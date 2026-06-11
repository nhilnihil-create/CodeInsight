#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }

  int count4 = 0;
  int count2 = 0;
  rep(i, n) {
    if (a[i] % 4 == 0) {
      count4++;
    } else if (a[i] % 2 == 0) {
      count2++;
    }
  }
  int countNot = n - count4 - count2;
  countNot += count2 == 0? 0 : 1;

  if (count4 + 1 >= countNot) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}