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

ll N, W;
ll w[110], v[110];
ll sum0[110], sum1[110], sum2[110], sum3[110];
vector<ll> w0, w1, w2, w3;
int main(){
  cin >> N >> W;
  cin >> w[0] >> v[0];
  w0.push_back(v[0]);
  for(int i = 1; i < N; i++){
    cin >> w[i] >> v[i];
    if(w[0] == w[i]) w0.push_back(v[i]);
    if(w[0]+1 == w[i]) w1.push_back(v[i]);
    if(w[0]+2 == w[i]) w2.push_back(v[i]);
    if(w[0]+3 == w[i]) w3.push_back(v[i]);
  }
  sort(w0.begin(), w0.end());
  sort(w1.begin(), w1.end());
  sort(w2.begin(), w2.end());
  sort(w3.begin(), w3.end());
  reverse(w0.begin(), w0.end());
  reverse(w1.begin(), w1.end());
  reverse(w2.begin(), w2.end());
  reverse(w3.begin(), w3.end());
  rep(i, w0.size()) sum0[i+1] = sum0[i] + w0[i];
  rep(i, w1.size()) sum1[i+1] = sum1[i] + w1[i];
  rep(i, w2.size()) sum2[i+1] = sum2[i] + w2[i];
  rep(i, w3.size()) sum3[i+1] = sum3[i] + w3[i];
  ll ans = 0;
  for(int i = 0; i <= w0.size(); i++){
    for(int j = 0; j <= w1.size(); j++){
      for(int k = 0; k <= w2.size(); k++){
        for(int l = 0; l <= w3.size(); l++){
          if(i * w[0] + j * (w[0] + 1) + k * (w[0] + 2) + l * (w[0] + 3) > W) continue;
          ans = max(ans, sum0[i]+sum1[j]+sum2[k]+sum3[l]);
        }
      }
    }
  }
  cout << ans << endl;
}
