#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
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

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define revrep(i, n) for(ll i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 1000000000;//10^9
ll MOD  = 1000000007;
//vector<int> dy = {0,0,1,-1};
//vector<int> dx = {1,-1,0,0};

vector<int> pow_change(vector<int> &c, ll n){
  vector<int> res(c.size()), c_(c.size());
  rep(i, c.size()) res[i] = i;
  while(n > 0){
    if(n&1){
      rep(i, c.size()){
        c_[i] = res[c[i]];
      }
      res = c_;
    }
    rep(i, c.size()){
      c_[i] = c[c[i]];
    }
    c = c_;
    n >>= 1;
  }
  return res;
}

int main(void){
  ll N; cin >> N;
  vector<ll> x(N); rep(i, N) cin >> x[i];
  ll M, K; cin >> M >> K;
  vector<ll> a(M); rep(i, M) cin >> a[i];

  vector<ll> d(N-1); rep(i, N-1) d[i] = x[i+1] - x[i];
  vector<int> change(N-1); rep(i, N-1) change[i] = i;
  rep(i, M) swap(change[a[i]-2], change[a[i]-1]);
  change = pow_change(change, K);
  ll position = x[0];
  cout << position << endl;
  rep(i, N-1){
    position += d[change[i]];
    cout << position << endl;
  }
}
