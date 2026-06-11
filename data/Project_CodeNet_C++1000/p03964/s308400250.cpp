#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    int n; cin >> n;
    vector<pint> senkyo(n);
    for (int  i = 0; i < n; i ++) {
        cin >> senkyo[i].first >> senkyo[i].second;
    }

    ll t = senkyo[0].first;
    ll a = senkyo[0].second;
    for (int i = 1; i < n ; i ++) {
        ll ti = senkyo[i].first;
        ll ai = senkyo[i].second;
        ll n = max((t + ti - 1)/ti, (a + ai - 1)/ai);
        t = n * ti;
        a = n * ai;
    }

    cout << t + a << endl;
}

