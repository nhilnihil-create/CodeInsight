#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int x, y;
  cin >> x >> y;
  int xg, yg;
  if(x == 2){
    xg = 1;
  }
  else if (x == 4 ||x == 6 || x == 9 || x == 11){
    xg = 2;
  }
  else xg = 3;

  if(y == 2){
    yg = 1;
  }
  else if (y == 4 || y == 6 || y == 9 || y == 11){
    yg = 2;
  }
  else yg = 3;

  if(xg == yg) cout << "Yes" << endl;
  else cout <<"No" << endl;

  return 0;
}
