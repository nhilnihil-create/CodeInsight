#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    ll n = s.size();
    map<char, int> mp;
    rep(i, n) {
        mp[s[i]]++;
    }

    ll ans = n * (n - 1) / 2LL;
    for(auto p : mp) {
        ll x = p.second;
        ans -= x * (x - 1) / 2LL;
    }

    cout << ans + 1 << endl;

    return 0;
}
