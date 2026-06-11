#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int n;
    cin >> n;
    vector <int> a(n, 0);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }

    bool ok = true;
    
    if (n%2) {
        if (a[0] != 1) ok = false;
        for (int i = 2; i <= n-1; i+=2) {
            if (a[i] != 2) ok = false;
        }
    } else {
        for (int i = 1; i <= n-1; i+=2) {
            if (a[i] != 2) ok = false;
        }
    }

    if (!ok) {
        cout << 0 << endl;
    } else {
        ll ans = 1;
        for (int i = 0; i < n/2; i++) {
            ans *= 2;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}

