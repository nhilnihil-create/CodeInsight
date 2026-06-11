#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP2(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define REPR(i, n) for (int i = (n)-1; i >= 0; --i)
#define REPR2(i, m, n) for (int i = (n)-1; i >= (m); --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTR(a) sort(ALL(a), greater<int>())
#define REVERSE(a) reverse(ALL(a))
#define bit_search(bit, n) REP(bit, 1<<(n))
#define bit_check(bit, i) (bit>>(i)) & 1
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) lower_bound(ALL(a), (x)) - a.begin()
#define bisect_right(a, x) upper_bound(ALL(a), (x)) - a.begin()
#define INPUT(a) REP(i, a.size()) cin >> a[i];
#define INPUTP(a) REP(i, a.size()) cin >> a[i].first >> a[i].second;
#define ENDL cout << endl;
using namespace std;
using ll = long long;
using ld = long double;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VI = vector<int>;
using VVI = vector<VI>;
using Vll = vector<ll>;
using VVll = vector<Vll>;
using VC = vector<char>;
using VS = vector<string>;
using VB = vector<bool>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  string S1, S2;
  cin >> S1 >> S2;
  ll ans = 1;
  int idx = 0;
  bool flg_1 = false, flg_2 = false;
  if (S1[0] == S2[0])
  {
    flg_1 = true;
    ans *= 3;
    idx++;
  }
  else
  {
    flg_2 = true;
    ans *= 3*2;
    idx += 2;
  }
  while(idx < N)
  {
    if (S1[idx] == S2[idx])
    {
      flg_2 = false;
      if (flg_1) ans *= 2;
      else flg_1 = true;
      idx++;
    }
    else
    {
      flg_1 = false;
      if (flg_2) ans *= 3;
      else
      {
        flg_2 = true;
        ans *= 2;
      }
      idx += 2;
    }
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}