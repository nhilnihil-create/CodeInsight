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


int main(){
  string s;
  cin >> s;
  int cnt = 0;
  int mxcnt = 0;
  int status = 0; //0: find a, 1: find z;
  REP(i,s.size()){
    if(status == 0){
      if(s[i] == 'A'){
        status = 1;
        cnt++;
      }
    }
    else{
      cnt++;
      if(s[i] == 'Z'){
        mxcnt = max(cnt, mxcnt);
      }
    }
  }

  cout << mxcnt << endl;
  return 0;
}