#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <regex>
#include <locale>

#include <iomanip>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_Len=int(b);i<i##_Len;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

int main () {
  int x, a, b;
  cin >> x >> a >> b;
  cout << (abs(a-x) < abs(b-x) ? "A" : "B") << endl;
}