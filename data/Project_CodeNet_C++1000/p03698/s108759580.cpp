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

  string s;
  cin >> s;
  
  vector<int> a(s.size(),0);
  
  for ( int i = 0; i < s.size(); i++){
    for ( int j = 0; j < s.size(); j++){
      if ( s[i] == s[j] ){
        a[i]++;
        if ( a[i] == 2 ){
          cout << "no" << endl;
          return 0;
        }
      }
    }
  }
  
  cout << "yes" << endl;
  
}