#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
long long dp[100010];
long long h[100010];

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    ll pari = 0;
    rep(i, n)
    {
        cin >> a[i];
        pari += a[i];
    }
    if (pari % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}