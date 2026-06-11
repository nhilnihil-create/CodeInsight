#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define P pair<int, int>
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define GI(name) \
  int(name);     \
  scanf("%d", &(name))
#define GI2(name1, name2) \
  int(name1), (name2);    \
  scanf("%d %d", &(name1), &(name2))
#define GI3(name1, name2, name3) \
  int(name1), (name2), (name3);  \
  scanf("%d %d %d", &(name1), &(name2), &(name3))
#define GVI(name, size)    \
  vector<int>(name)(size); \
  FOR(i, (size)) scanf("%d", &(name)[i])
#define GS(name) \
  string(name);  \
  cin >> (name);
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  FOR(i, v.size() - 1) { ret += to_string(v[i]) + ","; }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() {
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

#define MAX 300000
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
  GI2(H, W);
  GI2(A, B);
  COMinit();
  ll ans = COM((H - 1) + (W - 1), (H - 1));
  A = H - A;
  B = B - 1;
  while (A < H && B >= 0) {
    ans = (ans + MOD -
           COM(A + B, A) * COM((H - A - 1) + (W - B - 1), H - A - 1) % MOD) %
          MOD;
    A++;
    B--;
  }
  print(ans);
  return 0;
}