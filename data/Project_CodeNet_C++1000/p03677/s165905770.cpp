#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 + 100;
vector<pair<ll, ll>> bst[SIZE];
vector<ll> pref;

int main()
{
    fastInp;

    ll n, m;
    cin >> n >> m;
    vector<ll> vec(n), pref(m * 2 + 1), inc(m * 2), val(m * 2);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        --vec[i];
    }

    for (int i = 1; i < n; i++) {
        ll u = vec[i], v = vec[i - 1];
        if (u < v) u += m;

        s += (u - v);
        inc[v + 1]++;
        pref[u + 1] -= (u - v - 1);
        inc[u]--;
    }

    ll ans = s;
    ll cur = 0, curInc = 0;

    for (int i = 0; i < m * 2; i++) {
        cur += curInc;
        cur += pref[i];
        curInc += inc[i];
        val[i % m] += cur;
        if (i >= m) {
            ans = min(ans, s - val[i % m]);

        }
    }

    cout << ans;
    return 0;    
}