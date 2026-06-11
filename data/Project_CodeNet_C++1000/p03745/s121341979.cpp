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
  //in
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int flg = 0; //0; none 1: up, -1: down
  int cnt = 0;
  REP(i,n-1){
    if(flg > 0){
      if(a[i] > a[i+1]){
        //cnt++;
        flg = 0;
      }
    }
    else if(flg < 0){
      if(a[i] < a[i+1]){
        //cnt++;
        flg = 0;
      }
    }
    else if(flg == 0){ //flg == 0 
      if(a[i] < a[i+1]) {
        flg = 1; 
        cnt++;
      }
      else if(a[i] > a[i+1]){
        flg =  -1;
        cnt++;
      }
    }
    debug(flg);
    debug(cnt);
  }

  if(flg == 0) cnt++;
  cout << cnt << endl;


  //状態の判定用フラグと，カウンタの用意


  //out
  return 0;
}