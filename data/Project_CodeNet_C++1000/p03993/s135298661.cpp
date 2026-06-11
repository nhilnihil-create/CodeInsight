#include <bits/stdc++.h>

#define NREP() for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define MSG(x) cout << x << endl;
#define IPT(x) ll t; cin >> t; x.push_back(t);
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<string> vvs;

const static ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;

    ll a[100010];
    bool checked[100010];

    NREP() {
        cin >> a[i];
        checked[i] = false;
    }

    ll ans = 0;
    NREP() {
        if (checked[i]) continue;
        if (a[a[i] - 1] == i + 1) {
            ans++;
            checked[i] = true;
            checked[a[i] - 1] = true;
        }
    }

    MSG(ans)
}
