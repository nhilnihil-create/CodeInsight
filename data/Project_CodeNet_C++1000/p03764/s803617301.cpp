#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;
#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define mset(a,x) memset(a,x,sizeof(a))
#define FASTIO cin.tie(0),ios::sync_with_stdio(0)

const int mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    for (auto&& i : x) scanf("%d", &i);
    for (auto&& i : y) scanf("%d", &i);

    ll ans = 0;
    ll xs = 0, ys = 0;
    rep(i, n) {
        xs += 1LL * i * x[i] - 1LL * (n - i - 1) * x[i];
        xs %= mod;
    }
    rep(i, m) {
        ys += 1LL * i * y[i] - 1LL * (m - i - 1) * y[i];
        ys %= mod;
    }

    cout << (xs * ys) % mod << endl;

    return 0;
}