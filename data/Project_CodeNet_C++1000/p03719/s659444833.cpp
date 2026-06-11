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
  int a[3];
  rep(i, 3) cin >> a[i];
  
  cout << (a[0] <= a[2] && a[2] <= a[1] ? "Yes" : "No") << endl;
}