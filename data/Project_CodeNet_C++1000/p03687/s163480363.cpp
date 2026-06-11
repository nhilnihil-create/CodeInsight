#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

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

bool check(vector<char> &proc, char target, ll len) {
  REP(i, len) {
    if (proc[i] != target) return false;
  }
  return true;
}

ll f(string s, char target) {
  vector<char> proc(s.begin(), s.end());

  REP(i, s.size()) {
    ll len = s.size() - i;
    if (check(proc, target, len)) {
      return i;
    }
    REP(j, len - 1) {
      if (proc[j + 1] == target) {
        proc[j] = target;
      }
    }
  }
  return -1;
}

int main() {
  string input(s);
  set<char> parts(s.begin(), s.end());

  ll minv = 1ll << 60;
  for (auto v: parts) {
    minv = min(minv, f(s, v));
  }
  cout << minv << endl;
}
