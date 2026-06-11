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
#define fi first
#define se second
using namespace std;

const int64_t mod = 1000000007;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t n;
  cin >> n;
  map<int64_t, int64_t> prime;
  for(int64_t num = 2; num <= n; num++) {
    int64_t N = num;
    for(int64_t i = 2; i * i <= N; i++) {
      while(N % i == 0) {
        N /= i;
        prime[i]++;
      }
    }
    if(N != 1) prime[N]++;
  }

  int64_t res = 1;
  for(auto p : prime) {
    res *= (p.se+1);
    res %= mod;
  }
  cout << res << endl;
  return 0;
}