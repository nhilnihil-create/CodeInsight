#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int K;
  cin >> K;
  int n = 50;
  vint a(n);
  rep(i, n) a[i] = i + K/n;
  rep(i, K%n) {
    int mni = 0;
    rep(j, n) if(a[mni] > a[j]) mni = j;
    a[mni] += n;
    rep(j, n) if(j != mni) --a[j];
  }
  cout<<n<<endl;
  rep(i, n) cout << a[i] << " \n"[i==n-1];

  return 0;
}
