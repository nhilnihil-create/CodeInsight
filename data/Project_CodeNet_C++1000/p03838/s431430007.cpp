#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
const int INF = 1001001001;
int main(){
  int x, y;
  cin >> x >> y;
  int ry = y * -1;
  int rx = x * -1;
  int a1 = INF, a2 = INF, a3 = INF;
  if(x <= y){
    a1 = y - x;
    if(rx <= y) a2 = y - rx + 1;
    if(x <= ry) a3 = ry - x + 1;
  }else{
    a1 = ry - rx + 2;
    if(x <= ry) a2 = ry - x + 1;
    if(rx <= y) a3 = y - rx + 1;
  }
  if(a1 < a2 && a1 < a3) cout << a1 << endl;
  else if(a2 < a3) cout << a2 << endl;
  else cout << a3 << endl;
  return 0;
}