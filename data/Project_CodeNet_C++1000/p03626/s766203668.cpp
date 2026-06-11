#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main()
{
  int N;
  cin >> N;
  string S1, S2;
  cin >> S1 >> S2;
  ll ans = S1[0] == S2[0] ? 3 : 6;
  int before = S1[0] == S2[0] ? 0 : 1;
  int pos = S1[0] == S2[0] ? 1 : 2;
  while (pos < N)
  {
    if (before)
      ans *= S1[pos] == S2[pos] ? 1 : 3;
    else
      ans *= 2;
    ans %= MOD;
    before = S1[pos] == S2[pos] ? 0 : 1;
    pos += S1[pos] == S2[pos] ? 1 : 2;
  }
  cout << ans << endl;
  return 0;
}