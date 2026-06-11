#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// debug
#define test(x) cout << #x << " = " << x << endl

// answer output
#define Yes(c) cout << ((c) ? "Yes" : "No") << endl;
#define YES(c) cout << ((c) ? "YES" : "NO") << endl;
#define yes(c) cout << ((c) ? "yes" : "no") << endl;
 
#define possible(c) cout << ((c) ? "possible" : "impossible") << endl;
#define POSSIBLE(c) cout << ((c) ? "POSSIBLE" : "INPOSSIBLE") << endl;

int main() {

  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  if ( c >= b || a >= d ){
    cout << 0 << endl;
    return 0;
  }
  
  if ( d >= b && c >= a ){
    cout << b - c << endl;
  }else if ( b >= d && c >= a ){
    cout << d - c << endl;
  }else if ( b >= d && a >= c ){
    cout << d - a << endl;
  }else if ( d >= b && a >= c ){
    cout << b - a << endl;
  }else if ( b == d && a == c ){
    cout << b - a << endl;
  }

}