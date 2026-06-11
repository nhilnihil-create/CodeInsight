#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <regex>
#include <locale>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define all(x) (x).begin(),(x).end()

using ll = long long;

int main () {
  int a, b;
  cin >> a >> b;
  set s1 = {1,3,5,7,8,10,12};
  set s2 = {4,6,9,11};
  
  if (a == 2) {
    if (s1.count(b) > 0 || s2.count(b) > 0) {
      cout << "No" << endl;
    }
  } else if (b == 2) {
    if (a == 1) cout << "No" << endl;
  } else if ((s1.count(a) > 0 && s2.count(b) > 0) ||
             (s1.count(b) > 0 && s2.count(a) > 0)) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}