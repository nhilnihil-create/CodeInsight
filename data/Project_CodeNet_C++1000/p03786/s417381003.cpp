#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define chmax(x,y) x = max(x, y)
#define chmin(x,y) x = min(x, y)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> sum(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    rep(i, n) {
        if(i == 0) sum[i] = (ll) a[i];
        else sum[i] = sum[i - 1] + (ll) a[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        if(sum[i-1] * 2 < a[i]) {
            cout << n - i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
