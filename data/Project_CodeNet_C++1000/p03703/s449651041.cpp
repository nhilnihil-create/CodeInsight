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


ll bit[1<<18];
void bit_add(ll i, ll x){
  int cnt = 0;
  while(i <= (ll)(1<<18)){
    bit[i] += x;
    i += i & -i;
  }
}

ll bit_sum(ll x){
  ll res = 0;
  while(x > 0){
    res += bit[x];
    x -= x & -x;
  }
  return res;
}

ll Tnt(vector<ll> S){
  ll res = 0;
  for(int i = 0; i < S.size(); i++){
    res += i - bit_sum(S[i]);
    bit_add(S[i], 1);
  }
  return res;
}

void compress(vector<ll> &S){
  vector<ll> xs;
  rep(i, S.size()) xs.push_back(S[i]);
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  rep(i, S.size()){
    S[i] = lower_bound(xs.begin(), xs.end(), S[i]) - xs.begin() + 1;
  }
}

ll N, K;
vector<ll> A(200010);
vector<ll> S(200010);
int main(){
  cin >> N >> K;
  A.resize(N);
  S.resize(N+1);
  rep(i, N){
    cin >> A[i]; A[i] -= K;
  }
  rep(i, N) S[i+1] = S[i] + A[i];
  compress(S);
  cout << (N+1) * N / 2 - Tnt(S) << endl;
}
