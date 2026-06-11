#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <regex>
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,j,n) for(int i = j; i < n; i++)
#define rrep(i,j,n) for(intr i = j-1; i >= n; i--)
#define prec(n) fixed << setprecision(n)
#define print64_t_array(v) rep(__k, v.size()) { cout << v[__k]; if(__k != v.size()-1) cout << " "; else cout << endl; }
#define YesorNo(a) print64_tf(a?"Yes\n":"No\n")
#define MOD 1e+7
#define inf 1e9
#define fi first
#define se second
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t n;
  cin >> n;
  map<int64_t, int64_t, greater<int64_t>> mp;
  rep(i,n) {
    int64_t a;
    cin >> a;
    mp[a]++;
  }

  int64_t res = 1, idx = 2;
  for(auto P : mp) {
    int64_t f = P.fi;
    int64_t s = P.se / 2;
    //cout << f << " " << s << endl;
    while(s > 0 && idx > 0) {res *= f; s--; idx--;}
  }
  if(idx == 2) res = 0;
  cout << res << endl;
  return 0;
}