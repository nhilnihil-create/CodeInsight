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

typedef long long ll;
//typedef pair<int,int> Pint;
//typedef pair<ll, ll> P;
//typedef pair<ll, pair<ll, ll>> P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define revrep(i, n) for(ll i = n-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
const ll MOD = 1e9 + 7;
//ll MOD  = 998244353;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
ll pow_mod(ll x, ll k){
  x %= MOD; x += MOD; x %= MOD;
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}
ll inverse(ll x){return pow_mod(x, MOD - 2);};
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

int main(void){
  ll N;
  cin >> N;
  vector<ll> T(N);
  rep(i, N) cin >> T[i];
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  if(T[N-1] != A[0]){
    cout << 0 << endl;
    return 0;
  }
  vector<pair<ll, ll>> R(N);
  rep(i, N){
    R[i].f = 1;
    R[i].s = T[N-1];
  }
  R[0].f = R[0].s = T[0];
  //Tについての条件
  for(int i = 1; i < N; i++){
    if(T[i-1] == T[i]){
      R[i].s = T[i];
    }else{
      R[i].f = R[i].s = T[i];
    }
  }

  if(R[N-1].f > A[N-1] || R[N-1].s < A[N-1]){
    cout << 0 << endl;
    return 0;
  }else{
    R[N-1].f = R[N-1].s = A[N-1];
  }

  for(int i = N - 2; i >= 0; i--){
    if(A[i] == A[i+1]){
      R[i].s = min(R[i].s, A[i]);
    }else{
      if(R[i].f > A[i] || R[i].s < A[i]){
        cout << 0 << endl;
        return 0;
      }else{
        R[i].f = R[i].s = A[i];
      }
    }
  }
  ll ans = 1;
  rep(i, N){
    ans *= R[i].s - R[i].f + 1;
    ans %= MOD;
  }
  cout << ans << endl;
}
