#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
ll const inf = LLONG_MAX / 2;

int main() {
  int N; cin >> N;
  vector<ll> A(N), sum(N); cin >> A;
  sort(A.begin(), A.end());
  rep(i, N) sum[i] += (i ? sum[i - 1] : 0) + A[i];
  rep(i, N) sum[i] *= 2;
  int p = 0;
  REP(i, 1, N - 1) {
    if (sum[i - 1] < A[i]) {
      p = std::max(p, i);
    }
  }
  cout << N - p << "\n";
}
