#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, a, b, c, d;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b >> c >> d;
    
    bool pos = false;
    for (ll i = 1; i < n - 1; ++i) {
        ll lb = a + c * i, ub = a + d * i;
        lb -= (d * (n - 1 - i)), ub -= (c * (n - 1 - i));
        if (b >= lb && b <= ub) {
            pos = true;
            break;
        }
    }

    if (pos) cout << "YES";
    else cout << "NO";
}
