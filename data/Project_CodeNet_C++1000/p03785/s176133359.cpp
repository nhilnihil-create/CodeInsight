#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main()
{
  int N;
  ll C, K;
  cin >> N >> C >> K;
  vector<ll> A(N);
  REP(i, N)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  ll ans = 1,cnt=0,l=A.at(0)+K;
  REP(i,N){
    cnt++;
    if(C<cnt||l<A[i]){
      ans++;
      l = A[i] + K;
      cnt = 1;
    }
  }
  cout << ans << endl;
}