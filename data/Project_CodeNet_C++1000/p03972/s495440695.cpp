#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
vector<P> x;
int main() {
  ll w,h;
  cin >> w >> h;
  for(int i = 0; i < w; i++) {
    ll p;
    cin >> p;
    x.push_back(P(p,0));
  }
  for(int i = 0; i < h; i++) {
    ll p;
    cin >> p;
    x.push_back(P(p,1));
  }
  sort(x.begin(),x.end());

  ll ans = 0;
  w++,h++;
  for(int i = 0; i < x.size(); i++) {
    if(x[i].second == 0) {
      ans += h * x[i].first; w--;
    }
    else {
      ans += w * x[i].first; h--;
    }
  }

  cout << ans << endl;
}
  
