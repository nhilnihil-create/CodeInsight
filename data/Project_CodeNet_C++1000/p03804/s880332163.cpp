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
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

bool solve(int h, int w, vector<string> &a, vector<string> &b){
  int n = b.size();
  bool ok = true;
  REP(i,n)REP(j,n){
    if(a[i+h][j+w] != b[i][j]) ok = false;
  }
  return ok;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];


  bool  ok = false;
  REP(i,n)REP(j,n){
    if(i > n - m || j > n - m ) continue;
    //cout << i << " " << j << endl;
    if(solve(i,j,a,b)) {
      ok = true;
      break;
    }
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}