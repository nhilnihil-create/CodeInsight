#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {

    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    ll menor1L = min(4 * q, min(2 * h, s));
    ll menor2L = min(2 * menor1L, d);

    ll ans = (n / 2) * menor2L + (n & 1) * menor1L;

    cout << ans << endl;

    return 0;
}