#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#ifdef TESTING
  #include "dump.hpp"
#else
  #define DUMP(...)
  #define DEBUG(...)
#endif

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
#define SZ(a) int((a).size())
#define _REP(_1,_2,_3,_4,name,...) name
#define _REP4(i,b,e,s) for(decltype(e) _b=(b),_e=(e),i=_b+(0<(s)?0:(s));(0<(s)?i<_e:_e<=i);i+=(s))
#define _REP3(i,b,e) for(decltype(e) _b=(b),_e=(e),i=(_b<_e?_b:_b-1);(_b<_e?i<_e:_e<=i);(_b<_e?i++:i--))
#define _REP2(i,n) for(decltype(n) i=0,_n=(n);i<_n;i++)
#define _REP1(n) for(decltype(n) _i=0,_n=(n);_i<_n;_i++)
#define REP(...) _REP(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define FOR(it,c) for(auto&& it=begin(c);it!=end(c);it++)
#define ROF(it,c) for(auto&& it=rbegin(c);it!=rend(c);it++)
template<class T> inline string TOSTRING(T x) {ostringstream sout;sout<<x;return sout.str();}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  bool DBG = false; ull n, N, tmp;
  if (DBG){cin >> N;}
  auto check = [&](ull n){
    string rtn;
    cout << "? " << n << endl << flush;
    if (DBG){
      if ((n <= N) == (TOSTRING(n) <= TOSTRING(N))){
        rtn = "Y";
      } else {
        rtn = "N";
      }
      cout << rtn << endl;
    } else {
      cin >> rtn;
    }
    return rtn[0];
  };

  if (check(10000000000) == 'Y'){
    REP(i, 10, 1){
      n = 1;
      ull tmp = (ull) round(pow(10, i)) - 1;
      if (check(tmp) == 'N'){
        n = tmp + 1;
        break;
      }
    }
  } else {
    ull l = 1, r = 1000000000, m;
    REP(i, 1, 10){
      tmp = (ull) round(pow(10, i));
      if (check(tmp) == 'N'){
        l = tmp / 10, r = tmp - 1;
        break;
      }
    }
    while (l + 1 < r){
      m = (l + r) / 2;
      if (check(10 * m) == 'Y'){
        r = m;
      } else {
        l = m;
      }
    }
    n = r;
  }
  cout << "! " << n << endl << flush;
  return 0;
}