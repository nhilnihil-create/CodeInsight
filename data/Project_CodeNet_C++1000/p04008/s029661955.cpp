#pragma GCC optimize("trapv")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 + 100, INF = 1e9 + 10, MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 100;
bool used[SIZE];
vector<ll> s;
vector<vector<ll>> gr;
ll mxDist[SIZE];
ll k;

ll ans = 0;
void dfs(int v) {
    ll dst = 0;
    for (auto to : gr[v]) {
        dfs(to);
        if (mxDist[to] + 1 == k && v != 0) {
            mxDist[to] = -INF;
            ans++;
        }
        dst = max(dst, mxDist[to] + 1);
    }

    mxDist[v] = dst;
}
signed main()
{
    fastInp;

    ll n;
    cin >> n >> k;

    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    if (vec[0] != 1) ans++;
    vec[0] = 1;
    
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        gr[vec[i] - 1].push_back(i);
    }

    dfs(0);

    cout << ans;

    return 0;
}