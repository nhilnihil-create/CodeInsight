#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<ll> used(m + 1, 0), sport(m + 1, 0);
    for(i = 0; i < n; i++) {
        sport[a[i][0]]++;
    }
    ll ret = 0, now;
    for(i = 0; i < m + 1; i++) {
        ret = max(ret, sport[i]);
        if(ret==sport[i])now = i;
    }
    used[now] = 1;
    for(k = 0; k < m - 2; k++) {
        for(i = 0; i < m + 1; i++) {
            sport[i] = 0;
        }
        for(i = 0; i < n; i++) {
            j = 0;
            while(used[a[i][j]] == 1)
                j++;
            sport[a[i][j]]++;
        }
        ll tret = 0, now = 0;
        for(i = 0; i < m + 1; i++) {
            tret = max(tret, sport[i]);
            if(tret==sport[i])now = i;
        }
        ret = min(ret,tret);
        used[now] = 1;
    }
    cout << ret << endl;
    return 0;
}