#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string A;
map<char, ll> Last;
typedef tuple<ll, char, ll> State;
// length, first letter, next position
vector<State> Dp;

int main() {
  cin >> A;
  Dp.resize(A.size() + 1);
  Dp[A.size()] = State(1, 'a', -1);
  for (ll i = A.size() - 1; i >= 0; --i) {
    Last[A[i]] = i;
    State best;
    for (char c = 'a'; c <= 'z'; ++c) {
      State now = !Last.count(c)
                      ? State(1, c, -1)
                      : State(1 + get<0>(Dp[Last[c] + 1]), c, Last[c] + 1);
      if (c == 'a' || get<0>(now) < get<0>(best)) best = now;
    }
    Dp[i] = best;
  }
  for (ll i = 0; i != -1; i = get<2>(Dp[i])) cout << get<1>(Dp[i]);
  cout << endl;
  return 0;
}
