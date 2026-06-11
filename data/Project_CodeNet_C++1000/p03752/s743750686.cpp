#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <limits>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

template<class T>
void print(vector<T> a) {
  cout << "[ ";
  REP(i, a.size()) cout << a[i] << " ";
  cout << "]" << endl;
}

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

int main() {
  int input(n, k);
  vector<ll> a(n);
  REP(i, n) cin >> a[i];

  ll minv = numeric_limits<ll>::max();
  REP(i, 1 << n) {
    bitset<15> state(i);
    state[0] = 1;
    if (state.count() < k) continue;

    ll p = 0;
    ll cost = 0;
    REP(j, 15) {
      if (state[j]) {
        if (p >= a[j]) {
          cost += (p - a[j]) + 1;
          p++;
        }
      }
      p = max(p, a[j]);
    }
    minv = min(minv, cost);
  }
  cout << minv << endl;
}
