#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e18;
int main(){
  ll h, w;
  cin >> h >> w;
  ll res = INF;
  for (int k = 0; k < 2; k++) {
      for (int i = 1; i < h; i++) {
         ll a = i*w; 
         ll b = (w/2) * (h-i);
         ll c = ((w+1)/2) * (h-i);
         res = min(res, abs(max({a, b, c}) - min({a, b, c})));
         
         b = ((h-i)/2) * w;
         c = ((h-i+1)/2) * w;
         res = min(res, abs(max({a, b, c}) - min({a, b, c})));
      }
      swap(h, w);
   }
  cout << res << endl;
  return 0;
}