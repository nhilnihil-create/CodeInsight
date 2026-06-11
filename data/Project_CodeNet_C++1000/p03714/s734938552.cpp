#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vv = vector<vector<ll>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end());
#define MIN(vec) *std::min_element(vec.begin(), vec.end());
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ priority_queue<ll, vector<ll>, greater<ll>>

typedef pair<ll, ll> Pair;
bool pairCompare(const Pair &firstElof, const Pair &secondElof) {
  return firstElof.second > secondElof.second;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll LA[200001] = {};
ll RA[200001] = {};

int main() {
  ll N;
  vector<ll> A;
  cin >> N;
  REP(i, 3 * N) {
    ll a = 0;
    cin >> a;
    A.push_back(a);
  }
  ll sum = 0;
  PQ B;
  priority_queue<ll> C;
  REP(i, N) {
    sum += A[i];
    B.push(A[i]);
  }
  LA[N - 1] = sum;
  FOR(i, N, 2 * N) {
    B.push(A[i]);
    sum += A[i];
    sum -= B.top();
    B.pop();
    LA[i] = sum;
  }
  sum = 0;
  FOR(i, 2 * N, 3 * N) {
    sum += A[i];
    C.push(A[i]);
  }
  RA[2 * N] = sum;
  for (ll i = 2 * N - 1; i >= N; i--) {
    C.push(A[i]);
    sum += A[i];
    sum -= C.top();
    C.pop();
    RA[i] = sum;
  }
  ll max = -llINF;
  FOR(i, N - 1, 2 * N) {
    if (LA[i] - RA[i + 1] > max) {
      max = LA[i] - RA[i + 1];
    }
  }
  cout << max << endl;

  return 0;
}
