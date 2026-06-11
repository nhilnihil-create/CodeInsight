// Math = ♥️

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define ordered_set                            \
    tree<ll, null_type, less<ll>, rb_tree_tag, \
         tree_order_statistics_node_update>

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, ll> m, ind;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    m[0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        ind[arr[i]] = i;
    }

    vi ans(n, 0);
    ll curr = LLONG_MAX;
    for (auto it = m.rbegin(); it->ff != 0;) {
        curr = min(curr, ind[it->ff]);
        ll mult = it->ss;
        ll minus = it->ff;
        it++;
        minus -= it->ff;
        it->ss += mult;

        ans[curr] += mult * minus;
    }

    for (auto it : ans) {
        cout << it << "\n";
    }
}
