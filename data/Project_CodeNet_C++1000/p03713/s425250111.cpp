#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  ll h, w;
  cin >> h >> w;
  ll ans = LLONG_MAX;
  rep(i, 2){
    for(int j = 1; j < h; ++j){
      ll s1 = j * w;
      ll s2 = (h - j) / 2 * w;
      ll s3 = h * w - s2 - s1;
      ll mi = min(s1, min(s2, s3));
      ll ma = max(s1, max(s2, s3));
      ans = min(ans, abs(ma - mi));
      
      s2 = (h - j) * (w / 2);
      s3 = h * w - s2 - s1;
      mi = min(s1, min(s2, s3));
      ma = max(s1, max(s2, s3));
      ans = min(ans, ma - mi);
    }
    swap(h, w);
  }
  cout << ans << endl;
}