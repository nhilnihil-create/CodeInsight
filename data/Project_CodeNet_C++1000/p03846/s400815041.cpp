#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int m = (n+1)/2;
  vector<int> v(m);
  rep(i,n) {
    if((n&1)==(a[i]&1)){
      cout << 0 << endl;
      return 0;
    }
    int j = a[i]/2;
    if (j>=m || v[j] == 2){
      cout << 0 << endl;
      return 0;
    }
    v[j]++;
  }
  if((n&1) && v[0]>1){
    cout << 0 << endl;
    return 0;
  }

  int M =  1000000007;
  int ans = 1;
  rep(i,n/2) ans = ans*2%M;
  cout << ans << endl;

}