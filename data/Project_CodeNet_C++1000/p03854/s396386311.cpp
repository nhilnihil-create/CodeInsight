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
#define rrep(i,j,n) for(int i = j-1; i >= n; i--)
#define prec(n) fixed << setprecision(n)
#define print_array(v) rep(__k, v.size()) { cout << v[__k]; if(__k != v.size()-1) cout << " "; else cout << endl; }
#define YesorNo(a) printf(a?"Yes\n":"No\n")
#define MOD 1e+7
#define inf 1e9
#define fi first
#define se second
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  vector<string> str1 = {"dream", "erase"};
  vector<string> str2 = {"dreamer", "eraser"};
  reverse(s.begin(), s.end());
  rep(i,2) reverse(str1[i].begin(), str1[i].end());
  rep(i,2) reverse(str2[i].begin(), str2[i].end());

  while((int)s.size() >= 5) {
    if(s.substr(0,5) == str1[0]) {s = s.substr(5,s.size() - 5); continue;}
    if(s.substr(0,5) == str1[1]) {s = s.substr(5,s.size() - 5); continue;}
    if(s.substr(0,7) == str2[0]) {s = s.substr(7,s.size() - 7); continue;}
    if(s.substr(0,6) == str2[1]) {s = s.substr(6,s.size() - 6); continue;}
    cout << "NO" << endl;
    return 0;
  }
  cout << (s == "" ? "YES" : "NO") << endl;
  return 0;
}