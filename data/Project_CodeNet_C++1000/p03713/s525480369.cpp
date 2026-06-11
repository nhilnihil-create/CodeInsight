#include <bits/stdc++.h>
using namespace std;
#define ll long long  
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}

const ll MOD = 1e9+7;

void solve(){
  ll h, w; cin >> h >> w;
  if(h%3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return ;
  }
  ll ans = 1e15;
  ans = min(ans, h);
  ans = min(ans, w);
  //横に１本それから縦に１本
  for(int i = 1; i < h; ++i){
    ll mainheight = i;
    ll anotherheight = h-i;
    ll smax;
    ll smin;
    if(w%2 == 0){
      smax = max(w * mainheight, w / 2 * anotherheight);
      smin = min(w * mainheight, w / 2 * anotherheight);
    } else {
      smax = max(w * mainheight, (w / 2 + 1) * anotherheight);
      smin = min(w * mainheight, w / 2 * anotherheight);
    }
    ans = min(ans, smax-smin);
  }
  //縦に１本それから横に１本
  for(int i = 1; i < w; ++i){
    ll mainwidth = i;
    ll anotherwidth = w-i;
    ll smaxw;
    ll sminw;
    if(h%2 == 0){
      sminw = min(h * mainwidth, h / 2 * anotherwidth);
      smaxw = max(h * mainwidth, h / 2 * anotherwidth);
    } else {
      smaxw = max(h * mainwidth, (h / 2 + 1) * anotherwidth);
      sminw = min(h * mainwidth, h / 2 * anotherwidth);
    }
    ans = min(ans, smaxw-sminw);
  }
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}