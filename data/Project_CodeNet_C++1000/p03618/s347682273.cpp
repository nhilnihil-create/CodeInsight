#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

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

ll c(ll l) {
  return l * (l - 1) / 2;
}

int main() {
  string input(s);
  ll ans = c(s.size());
  ll n = s.size();
  map<char, ll> cnt;
  REP(i, n) {
    cnt[s[i]]++;
  }

  for(auto v: cnt) {
    ans -= c(v.second);
  }
  cout << ans + 1 << endl;
}
