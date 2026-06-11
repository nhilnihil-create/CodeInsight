#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const ll SIZE = 1e5 * 2 + 10, INF = 1e9;

vector<ll> vec;
ll sz[SIZE], hv[SIZE];

int main()
{
    fastInp;

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) sz[i] = 1;
    hv[0] = 1;

    while (m--) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        sz[v]++;
        sz[u]--;
        if (sz[v] >= 1 && hv[u]) hv[v] = 1;
        if (sz[u] == 0) hv[u] = 0;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += hv[i];

    cout << ans;
    return 0;
}