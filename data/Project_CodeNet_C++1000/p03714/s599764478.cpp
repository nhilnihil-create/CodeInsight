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
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define revrep(i, n) for(ll i = n-1; i >= 0; i--)
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}

ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 1000000000;//10^9
ll MOD  = 1000000007;
//vector<int> dy = {0,0,1,-1};
//vector<int> dx = {1,-1,0,0};


int main(){
  ll N; cin >> N;
  vector<ll> A(3 * N);
  rep(i, 3 * N) cin >> A[i];

  vector<ll> l(N+1);
  ll leftsum = 0;
  priority_queue<ll, vector<ll>, greater<ll>> left;
  for(int i = 0; i < N; i++){
    left.push(A[i]);
    leftsum += A[i];
  }
  l[0] = leftsum;
  for(int i = N; i < 2 * N; i++){
    ll a = left.top();
    left.pop();
    if(a > A[i]){
      left.push(a);
    }else{
      left.push(A[i]);
      leftsum += A[i] - a;
    }
    l[i-N+1] = leftsum;
  }

  reverse(A.begin(), A.end());
  vector<ll> r(N+1);
  ll rightsum = 0;
  priority_queue<ll> right;
  for(int i = 0; i < N; i++){
    right.push(A[i]);
    rightsum += A[i];
  }
  r[0] = rightsum;
  for(int i = N; i < 2 * N; i++){
    ll a = right.top();
    right.pop();
    if(a < A[i]){
      right.push(a);
    }else{
      right.push(A[i]);
      rightsum -= a - A[i];
    }
    r[i-N+1] = rightsum;
  }
  ll ans = - INFL;
  for(int i = 0; i < N+1; i++){
    ans = max(ans, l[i] - r[N-i]);
  }
  cout << ans << endl;

}
