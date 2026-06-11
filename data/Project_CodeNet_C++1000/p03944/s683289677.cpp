#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,b,c,d=0,e=0,f,g,h;
  cin >> a >> b >> c;
  rep(i,c){
    cin >> f >> g >> h;
    if(h==1) d = max(d,f);
    if(h==2) a = min(a,f);
    if(h==3) e = max(e,g);
    if(h==4) b = min(b,g);
  }
  if(d<=a&&e<=b)cout << (d-a) * (e-b);
  else cout << 0;
}
