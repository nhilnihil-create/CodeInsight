#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int w, h, n;
  cin >> w >> h >> n;
  int x1 = w, y1 = h;
  int x0 = 0, y0 = 0;

  int ans = 0;
  rep(i,n){
    int a, b, ai;
    cin >> a >> b >> ai;
    if (ai == 1 && a > x0) x0 = a;
    else if (ai == 2 && a < x1) x1 = a;
    else if (ai == 3 && b > y0) y0 = b;
    else if (ai == 4 && b < y1) y1 = b;
    ans = (x1 - x0) * (y1 - y0);
    if (ans < 0){
      ans = 0;
      break;
    }
  }
  cout << ans << endl;
}
