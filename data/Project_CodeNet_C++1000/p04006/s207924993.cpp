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

ll curBst[2001];

signed main()
{
    fastInp;

    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        curBst[i] = vec[i];
        ans += vec[i];
    }

    for (int i = 0; i < n; i++) {
        ll s = vec.front();
        vec.erase(vec.begin());
        vec.push_back(s);
        ll curS = 0;
        for (int j = 0; j < n; j++) {
            curBst[j] = min(curBst[j], vec[j]);
            curS += curBst[j];
        }
        ans = min(ans, curS + (i + 1) * x);
    }

    cout << ans;
    return 0;
}