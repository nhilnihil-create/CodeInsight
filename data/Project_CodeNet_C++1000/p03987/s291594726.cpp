#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pair<ll, ll>>> vvpll;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n;
    cin >> n;

    vl p(n), id(n+1);
    rep(i, n) {
        cin >> p[i];
        id[p[i]] = i;
    }

    set<ll> st;
    st.insert(-1);
    st.insert(n);
    ll ans = 0;
    exrep(x, 1, n) {
        ll i = id[x];
        st.insert(i);
        auto it1 = st.find(i);
        it1--;
        ll L = *it1;
        auto it2 = st.find(i);
        it2++;
        ll R = *it2;
        ans += x*(i - L)*(R - i);
    }

    out(ans);
    re0;
}