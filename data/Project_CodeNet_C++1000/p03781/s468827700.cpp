#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()
#define All(arr) arr.begin(), arr.end()

using namespace std;
typedef long long ll;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

#define Cins(T, n, xs) \
  vector<T> xs(n);     \
  for (int i = 0; i < n; ++i) cin >> xs[i]

void Main() {
  Cin(int, x);

  for (int i = 0; i <= x; ++i) {
    int sum = 0;
    for (int j = 0; j <= i; ++j) sum += j;
    if (sum >= x) {
      cout << i << endl;
      return;
    }
  }
}

int main() {
  cout << fixed << setprecision(15);
  Main();
  return 0;
}