#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  ll x = 1;
  vector<ll> t(n), a(n);
  rep(i, n) {
    cin >> t[i] >> a[i];
  }
  for(int i = 1; i < n; ++i) {
    x = max((a[i - 1] * x + a[i] - 1) / a[i], (t[i - 1] * x + t[i] - 1) / t[i] );
  }
  cout << x * t[n - 1] + x * a[n - 1] << endl;


}