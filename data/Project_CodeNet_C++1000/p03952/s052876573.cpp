// In The Name Of Allah

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pp pop_back
#define pb push_back
#define mp make_pair
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int maxx = 1e6 + 19;
const int inf = 1e18 + 19;
const int mod = 1000000007LL;

int n, m;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if (m == 1 || m == (2 * n) - 1)
        return cout << "No", 0;
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < 2 * n - 1; i++)
            cout << (i + m - n + 2 * n - 1) % (2 * n - 1) + 1 << endl;
    }
    return 0;
}
