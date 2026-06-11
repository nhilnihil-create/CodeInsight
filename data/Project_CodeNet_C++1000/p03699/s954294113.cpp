#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(),a.end());
  if(sum%10==0) {
    rep(i,n) {
      if(a[i]%10!=0) {
        sum -= a[i];
        break;
      }
      if(i==n-1) sum = 0;
    }
  }

  cout << sum << endl;
}
