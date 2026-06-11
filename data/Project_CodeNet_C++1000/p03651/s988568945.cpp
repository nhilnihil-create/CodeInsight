#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

#if __has_include("debugger.cpp")
  #include "debugger.cpp"
#else
void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) > 0) cout << " ";
  print(std::forward<Tail>(tail)...);
}
# endif

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

int main() {
  ll input(n, k);
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  if (*max_element(a.begin(), a.end()) < k) {
    print("IMPOSSIBLE");
    return 0;
  }
  ll p = a[0];
  REP(i, n - 1) {
    p = gcd(p, a[i + 1]);
  }
  print(k % p == 0 ? "POSSIBLE" : "IMPOSSIBLE");
}
