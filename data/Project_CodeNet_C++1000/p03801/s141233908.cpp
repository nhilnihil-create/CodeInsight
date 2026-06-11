#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    map<ll, ll> count;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (!mp[a[i]]) {
            mp[a[i]] = i + 1;
        } else {
            mp[a[i]] = min(mp[a[i]], i + 1);
        }
        count[a[i]]++;
    }
    sort(all(a), greater<ll>());
    a.erase(unique(a.begin(), a.end()), a.end());
    a.push_back(0);
    vector<ll> ans(n + 1, 0);
    for (int i = 0; i < a.size() - 1; i++) {
        ans[mp[a[i]]] += (a[i] - a[i + 1]) * count[a[i]];
        mp[a[i + 1]] = min(mp[a[i + 1]], mp[a[i]]);
        count[a[i + 1]] += count[a[i]];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i + 1] << endl;
    }
}
