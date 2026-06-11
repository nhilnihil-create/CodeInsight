#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct BIT {
  vector<ll> data;
  int N;

  BIT(int n) {
    N = n;
    data = vector<ll>(N+1);
  }

  void add(int i, ll x) {
    for (int k = i; k <= N; k += k&-k) data[k] += x;
  }

  void update(int i, ll x) {
    add(i, x-get(i));
  }

  ll sum(int i) {
    ll res = 0;
    for (int k = i; k > 0; k -= k&-k) res += data[k];
    return res;
  }

  ll get(int i) {
    return sum(i) - sum(i-1);
  }
};

struct miyage {
  int l, r, len;
};
bool comp (miyage x, miyage y) {
  return x.len < y.len;
}

#define REP(i,n) for (int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()

const int MAX = 3e5+10;

int N, M;
miyage a[MAX];

int main() {

  cin >> N >> M;
  REP (i, N) {
    cin >> a[i].l >> a[i].r;
    a[i].len = a[i].r-a[i].l+1;
  }
  sort(a, a+N, comp);
  BIT bit(MAX);

  int j = 0;
  for (int i = 1; i <= M; i++) {
    while (j < N && a[j].len < i) {
      bit.add(a[j].l, 1);
      bit.add(a[j].r+1, -1);
      j++;
    }
    int ans = 0;
    for (int k = 0; k <= M; k += i) ans += bit.sum(k);
    cout << ans +N-j << endl; 
  }

}