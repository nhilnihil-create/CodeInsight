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
  string sa, sb, sc;
  cin >> sa >> sb >> sc;

  char turn;
  turn = 'a';
  int apos = 0, bpos = 0, cpos = 0;

  while(1){
    //a
    if(turn == 'a'){
      if(apos == sa.size()){
        cout << 'A' << endl;
        return 0;
      }
      turn = sa[apos];
      apos++;
    }
    //b
    if(turn == 'b'){
      if(bpos == sb.size()){
        cout << 'B' << endl;
        return 0;
      }
      turn = sb[bpos];
      bpos++;
    }
    //a
    if(turn == 'c'){
      if(cpos == sc.size()){
        cout << 'C' << endl;
        return 0;
      }
      turn = sc[cpos];
      cpos++;
    }

  }


  return 0;
}