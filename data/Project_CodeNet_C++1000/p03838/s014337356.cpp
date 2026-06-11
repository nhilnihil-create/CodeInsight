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
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  int x,y;
  cin >> x >> y;
  int ans = 0;

  //Aボタン

  ans += abs(abs(x) - abs(y));

  //Bボタン
  if(abs(x) < abs(y)){
    if(x < 0) ++ans;
    if(y < 0) ++ans;
  }
  else if(abs(x) > abs(y)){
    if(x > 0) ++ans;
    if(y > 0) ++ans;
  }

  else{
    if( x != y) ++ans;
  }
  cout << ans << endl;
  return 0;
}