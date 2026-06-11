#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  ll ans = 0;
  rep(i, n) cin >> a[i];
  for(int i = 1; i < n; ++i){
    ans += min(t, a[i] - a[i - 1]);
  }
  ans += t;

  cout << ans << endl;
}