#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
  
bool chmax(ll& a, ll b) { if (a < b) { a=b; return true;} else return false;}
bool chmin(ll& a, ll b) { if (a > b) { a=b; return true;} else return false;}

const ll INF = 1 << 30;

int main(){
  ll h,w; cin >> h >> w;
  
  ll ans = INF;
  for(ll i = 1; i < h; ++i){
    chmin(ans, max({i*w, (h-i)/2*w, (h-i-(h-i)/2)*w}) - min({i*w, (h-i)/2*w, (h-i-(h-i)/2)*w}));
    chmin(ans, max({i*w, (h-i)*(w/2), (h-i)*(w-w/2)}) - min({i*w, (h-i)*(w/2), (h-i)*(w-w/2)}));
  }
  
  for(ll i = 1; i < w; ++i){
    chmin(ans, max({i*h, (w-i)/2*h, (w-i-(w-i)/2)*h}) - min({i*h, (w-i)/2*h, (w-i-(w-i)/2)*h}));
    chmin(ans, max({i*h, (w-i)*(h/2),(w-i)*(h-h/2)}) - min({i*h, (w-i)*(h/2),(w-i)*(h-h/2)}));
  }
  cout << ans << endl;
}