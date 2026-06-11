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
ll INFL = 1LL << 60;//10^18 = 2^60
int INF = 1 << 30;//10^9
ll MOD = 1e9 + 7;
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
ll lcm(ll x, ll y){return x / gcd(x, y) * y % MOD;};

ll memo[20000];
ll b[2][3], c[3][2];

bool allUmeted(ll x){
  ll X = x;
  bool l = 1;
  rep(i, 3)rep(j, 3){
    if(X % 3 == 0) l = 0;
    X /= 3;
  }
  return l;
}

ll score(ll state){
  ll S = state;
  int mp[3][3];
  rep(i, 3){
    rep(j, 3){
      if(state % 3 == 1) mp[i][j] = 0;
      else mp[i][j] = 1;
      state /= 3;
    }
  }
  ll res = 0;
  rep(i, 2)rep(j, 3) if(mp[i][j] == mp[i+1][j]) res += b[i][j];
  rep(i, 3)rep(j, 2) if(mp[i][j] == mp[i][j+1]) res += c[i][j];
  return res;
}

ll dfs(bool turn, ll state){
  if(memo[state] != -1) return memo[state];
  if(allUmeted(state)) return score(state);
  if(turn == 0){
    ll res = -INFL;
    rep(i, 9){
      if(state % pow_long(3, i+1) - state % pow_long(3, i) != 0){
        continue;
      }
      res = max(res, dfs(1, state + pow_long(3, i)));
    }
    return memo[state] = res;
  }else{
    ll res = INFL;
    rep(i, 9){
      if(state % pow_long(3, i+1) - state % pow_long(3, i) != 0){
        continue;
      }
      res = min(res, dfs(0, state + 2 * pow_long(3, i)));
    }
    return memo[state] = res;
  }
}


int main(){
  int N, x; cin >> N >> x;
  if(N == 2){
    if(x == 1 || x == 3){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
      cout << 1 << " " << 2 << " " << 3 << endl;
    }
    return 0;
  }

  if(x == 1 || x == 2 * N - 1){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  x--;
  vector<ll> used(2 * N - 1, 0);
  vector<ll> ans(2 * N - 1, -1);

  if(x == 1){
    ans[N-1] = x;
    ans[N-2] = x+1;
    ans[N] = x-1;
    ans[N+1] = x+2;
    used[x] = used[x+1] = used[x-1] = used[x+2] = 1;
    int s = 0;
    rep(i, 2*N-1){
      if(ans[i] != -1) continue;
      while(true){
        if(used[s] == 0) break;
        s++;
      }
      ans[i] = s;
      used[s] = 1;
    }
    rep(i, 2*N-2) cout << ans[i]+1 << " ";
    cout << ans[2*N-2]+1 << endl;
    return 0;
  }


  ans[N-1] = x;
  ans[N-2] = x-1;
  ans[N] = x + 1;
  ans[N+1] = x - 2;
  used[x] = used[x-1] = used[x+1] = used[x-2] = 1;
  int s = 0;
  rep(i, 2*N-1){
    if(ans[i] != -1) continue;
    while(true){
      if(used[s] == 0) break;
      s++;
    }
    ans[i] = s;
    used[s] = 1;
  }
  rep(i, 2*N-2) cout << ans[i]+1 << " ";
  cout << ans[2*N-2]+1 << endl;


}
