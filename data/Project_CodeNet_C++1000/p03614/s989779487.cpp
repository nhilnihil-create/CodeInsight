//=template===================================================================//
// include
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>

// namespace
using namespace std;

// define
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(i,n) FOR(i,0,n)
#define MIN_V(v) *min_element(v.begin(), v.end())
#define MAX_V(v) *max_element(v.begin(), v.end())

// typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef long long LL;
typedef unsigned long long ULL;
typedef struct {
  LL cost;
  bool done;
} node_t;

// conversion
inline int
toInt(string s)
{
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline int countChar(string s, char c) {int cnt,i; cnt=0; REP (i,s.size()) {if (s[i]==c) cnt++;} return cnt;}
template<class T> inline string toString(T x) {ostringstream sout; sout<<x; return sout.str();}

int main(void)
{
  // Scan begin.
  int n, i, cnt=0;
  cin >> n;
  // Scan done.

  // Code begin.
  bool flag = false;
  REP(i, n) {
    int p_i;
    cin >> p_i;
    if (p_i == (i+1)) {
      if (flag) {
        flag = false;
      }
      else {
        cnt++;
        flag = true;
      }
    }
    else{
      flag = false;
    }
  }
  // Code done.

  cout << cnt;

  return 0;
}