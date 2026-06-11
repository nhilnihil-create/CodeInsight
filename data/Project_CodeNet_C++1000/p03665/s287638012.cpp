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

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  REP(i,n)  cin >> a[i];

  bool isOdd = false;
  REP(i,n){
    if(a[i]%2 == 1) isOdd = true; 
  }

  ll ans= 0;
  if(isOdd) ans = pow(2,n-1);
  else {
    if(p == 0) ans = pow(2,n);
    else ans = 0;
  }

  cout << ans << endl;



  return 0;
}