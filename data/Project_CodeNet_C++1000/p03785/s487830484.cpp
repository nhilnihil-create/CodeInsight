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
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  REP(i,n) cin >> t[i];
  sort(ALL(t));

  debug(t);

  queue<int> q;
  
  //sort

  //キューを用意．サイズがｃになったらc人pop
  //　または，先頭が滞在可能時間を超えたらmin(c,q.size())人pop
  int cnt = 0;
  REP(i,n){

    if(!q.empty()){
      if(q.front() + k < t[i]){
        int tmp = min(int(q.size()), c);
        debug(tmp);
        REP(ci, tmp) q.pop();
        cnt++;
      }
    }

    q.push(t[i]);

    if(q.size() >= c){
      REP(ci,c) q.pop();
      cnt++;
    }

    debug(int(q.size()));
    debug(cnt);
  }
   debug(int(q.size()));

  if(!q.empty()){
    int tmp = q.size();
    cnt += (tmp+c-1)/c;
  }

  cout << cnt << endl;
  return 0;
}