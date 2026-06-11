#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

void _main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, 0, N) cin >> a[i];
    vector<ll> sum(N + 1);
    sum[0] = 0;
    vector<ll> alt;
    alt.push_back(0);
    rep(i, 0, N)
    {
        sum[i + 1] = sum[i] + a[i] - K;
        alt.push_back(sum[i + 1]);
    }
    sort(alt.begin(), alt.end());

    BinaryIndexedTree<ll> bit(N + 1);

    ll ans = 0;
    rep(i, 0, N + 1)
    {
        const int x = lower_bound(alt.begin(), alt.end(), sum[i]) - alt.begin();
        ans += bit.sum(x);
        bit.add(x, 1);
    }
    cout << ans << endl;
}
