#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

long dis(long h, long w, long x, long y){
  long z1 = max(x*w, max(y*(h-x), (w-y)*(h-x)));
  long z2 = min(x*w, min(y*(h-x), (w-y)*(h-x)));
  return z1 - z2;
}

int main(){
  long h,w;
  cin >> h >> w;
  if(h == 2 && w == 2){
    cout << 1 << endl;
    return 0;
  }
  long ans = 1e11;
  if(h > 2){
    if(h % 3 == 0) ans = 0;
    else ans = min(ans, w);
  }
  if(w > 2){
    if(w % 3 == 0) ans = 0;
    else ans = min(ans, h); 
  }
  long x = h/3;
  long y = w/2;
  ans = min(ans, dis(h,w,x,y));
  ans = min(ans, dis(h,w,x+1,y));
  x = w/3;
  y = h/2;
  ans = min(ans, dis(w,h,x,y));
  ans = min(ans, dis(w,h,x+1,y));
  cout << ans << endl;
}