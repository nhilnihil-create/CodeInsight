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
  vector<int64_t> a(n);
  rep(i,n) cin >> a[i];

  //2パターンの小さい方を出力しようとしています

  // + => - => + => ...
  //sum1はiまでの総和(正負を見る)
  //cost1はコスト
  int64_t sum1 = 0LL, cost1 = 0LL;
  rep(i,n) {
    sum1 += a[i];
    int64_t diff = abs(sum1) + 1LL;//+1か-1まで動かすための操作回数

    if(i % 2 == 0 && sum1 < 0LL) {sum1 += diff; cost1 += diff;}
    if(i % 2 == 1 && sum1 > 0LL) {sum1 -= diff; cost1 += diff;}
    if(sum1 == 0LL) {
      if(i % 2 == 0) {sum1++; cost1++;}
      if(i % 2 == 1) {sum1--; cost1++;}
    }
  }


  // - => + => - => ...
  //sum2はiまでの総和(正負を見る)
  //cost1はコスト
  int64_t sum2 = 0LL, cost2 = 0LL;
  rep(i,n) {
    sum2 += a[i];
    int64_t diff = abs(sum2) + 1LL;//+1か-1まで動かすための操作回数

    if(i % 2 == 0 && sum2 > 0LL) {sum2 -= diff; cost2 += diff;}
    if(i % 2 == 1 && sum2 < 0LL) {sum2 += diff; cost2 += diff;}

    if(sum2 == 0LL) {
      if(i % 2 == 0) {sum2--; cost2++;}
      if(i % 2 == 1) {sum2++; cost2++;}
    }
  }
  
  cout << min(cost1, cost2) << endl;
  return 0;
}