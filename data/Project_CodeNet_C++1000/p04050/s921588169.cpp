#include <bits/stdc++.h>

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ld eps = 1e-9, pi = acos(-1.0);

void output(const deque<int> &a) {
  REP(i,a.size()) {
    cout << a[i] << " \n"[i == (int)a.size() - 1];
  }
}

int main() {
  cout << setprecision(12) << fixed << boolalpha;
  int N, M;
  cin >> N >> M;
  deque<int> a, odd;
  REP(i,M) {
    int in; cin >> in;
    if (in % 2) odd.push_back(in);
    else a.push_back(in);
  }
  if (odd.size() > 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  REP(i,odd.size()) {
    if (i == 0) a.push_front(odd[i]);
    else a.push_back(odd[i]);
  }
  output(a);
  if (a.size() == 1) {
    a.push_front(0);
  }
  ++a.front();
  --a.back();
  if (a.back() == 0) a.pop_back();
  cout << a.size() << endl;
  output(a);
  return 0;
}
