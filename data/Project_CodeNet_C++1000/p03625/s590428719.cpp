#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
set<int> st[N + 1];

int main() {
    map<ll, ll> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    ll ans = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (it->second >= 4) {
            if (ans == 0) {
                cout << it->first * it->first;
                return 0;
            } else {
                cout << ans * it->first;
                return 0;
            }
        } else if (it->second >= 2) {
            if (ans == 0)
                ans = it->first;
            else {
                cout << it->first * ans;
                return 0;
            }

        }

    }
    cout<<0;

}