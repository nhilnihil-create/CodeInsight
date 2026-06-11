#include <cstdio>
#include <vector>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

typedef long long ll;
typedef vector<int> prm;

//------------------------------------------------------------------------------
prm mul(prm &A, prm &B) {
  prm C = prm(A.size());
  REP(i, A.size()) C[i] = B[A[i]];
  return C;
}

prm pow(prm &A, ll n) {
  prm B = prm(A.size());
  REP(k, A.size()) B[k] = k;
  while(n > 0) {
    if (n & 1) B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

//------------------------------------------------------------------------------
const int N_MAX = 100000;
const int M_MAX = 100000;

int N;
int x[N_MAX];
int M;
ll K;
int a[M_MAX];

void solve() {
  prm P = prm(N - 1);
  REP(k, P.size()) P[k] = k;
  REP(j, M) swap(P[a[j] - 1], P[a[j]]);
  prm Q = pow(P, K);
  ll ans = x[0];
  printf("%lld\n", ans);
  REP(i, N - 1) {
    ans += x[Q[i] + 1] - x[Q[i]];
    printf("%lld\n", ans);
  }
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", x + i);
  scanf("%d%lld", &M, &K);
  REP(i, M) {
    scanf("%d", a + i);
    --a[i];
  }
}

int main() {
  input();
  solve();
  return 0;
}
