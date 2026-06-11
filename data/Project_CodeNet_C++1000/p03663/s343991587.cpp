#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<queue>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

ll n,_10[17],_99[17];

char AI(string s) {
  string t = s.substr(2);
  ll v = atoll(t.c_str());
  if( s[0] == '?' ) {
    if( v <= n && t <= to_string(n) ) return 'Y';
    if( v >  n && t >  to_string(n) ) return 'Y';
    return 'N';
  } else {
    if( n == v ) return 'Y';
    else return 'N';
  }
}

/*
  123 < 124
  999 < 9999

  10^x と 9{x} で桁数は決まる ( 4 * 2 )
 */
void compute() {
  ll keta = 0;
  _10[0] = 1, _99[0] = 9;
  REP(i,1,17) {
    _10[i] = _10[i-1] * 10LL;
    _99[i] = _99[i-1] * 10LL + 9LL;
  }
  
  {
    ll L = 0, R = 10;
    while( R - L ){
      ll M = ( L + R ) / 2LL;
      cout << "? "+to_string(_10[M]) << endl;
      //char c = AI("? "+to_string(_10[M]));
      char c;
      cin >> c;
      if( c == 'Y' ) L = M + 1LL;
      else           R = M;  
    }
    if( L-1LL == 9LL ) {
      keta = -1;
    } else {
      keta = L;
    }
  }

  if( keta == -1 ) {
    ll L = 0, R = 10;
    while( R - L ){
      ll M = ( L + R ) / 2LL;
      cout << "? "+to_string(_99[M]) << endl;
      //char c = AI("? "+to_string(_99[M]));
      char c;
      cin >> c;
      if( c == 'N' ) L = M + 1LL;
      else           R = M;  
    }
    if( L-1LL == 9LL ) {
      keta = -1;
    } else {
      keta = L+1;
    }
  }

  if( keta == 1 ) {
    cout << "? 10" << endl;
    //char c = AI("? 10");
    char c;
    cin >> c;
    if( c == 'Y' ) {
      cout <<"! 1" << endl;
      return;
    }
  }

  string s = "";
  rep(i,keta) {
    ll L = 0, R = 10;
    while( R - L ){
      ll M = ( L + R ) / 2LL;
      cout << "? "+s+to_string(M) << endl;
      //char c = AI("? "+s+to_string(M));
      char c;
      cin >> c;
      if( c == 'Y' ) L = M + 1LL;
      else           R = M;  
    }
    s += to_string(L-1LL);
  }
  //cout << "! " << s << endl;
  s = s.substr(0,(int)s.size()-1);

  {  
    ll L = 0, R = 10;
    while( R - L ){
      ll M = ( L + R ) / 2LL;
      cout << "? "+s+to_string(M)+"1" << endl;
      //char c = AI("? "+s+to_string(M)+"1");
      char c;
      cin >> c;
      if( c == 'N' ) L = M + 1LL;
      else           R = M;  
    }
    cout << "! " << s + to_string(L) << endl;
  }
  
}

void test() {
  cin >> n;
  /*
  cin.ignore();
  rep(i,64) {
    string s;
    getline(cin,s);
    cout << AI(s) << endl;
    if( s[0] == '!' ) {
      return;
    }
  }
  */
  compute();
}

int main() {
  //test();
  compute();
  return 0;
}
