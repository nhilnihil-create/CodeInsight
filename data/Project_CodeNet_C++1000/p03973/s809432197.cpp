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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int x = 1;
    ll ans = 0;
    rep(i, n) {
        if(a[i] > x) {
            ans += (a[i] - 1) / x;
            a[i] = 1;
        }
        // cout << a[i] << " " << x << endl;
        if (a[i] == x) x++;
    }

    /*
    cout << "-------------------" << endl;
    rep(i, n) {
        cout << a[i] << endl;
    }
    */

    cout << ans << endl;

    return 0;
}
