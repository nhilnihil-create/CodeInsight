#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

typedef pair<int, int> Pi;
typedef tuple<int, int, int> Ti;
typedef vector<int> vint;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  int lb = 0, ub = N+1;
  while(lb+1 < ub) {
    int mb = (lb+ub)/2;
    if(mb*(mb+1)/2 >= N) ub = mb;
    else lb = mb;
  }
  vector<int> ans;
  for(int i = ub; i >= 1; i--) {
    if(N >= i) {
      N -= i;
      ans.push_back(i);
    }
  }
  reverse(all(ans));
  for(int a : ans) cout << a << endl;

  return 0;
}
