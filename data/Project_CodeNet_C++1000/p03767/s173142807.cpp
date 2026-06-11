#include <bits/stdc++.h>
using namespace std;
 
#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INFINITO 1000000000
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


int main() {

    int n;
    cin >> n;
    vi a(3 * n);

    fo(i, 3 * n) cin >> a[i];
    sort(all(a));

    ll ans = 0;

    for ( int i = 3 * n - 2; i >= n ; i -= 2 ) {
        // cout << a[i] << endl;
        ans += a[i];
    }

    cout << ans << endl;

    return 0;
}