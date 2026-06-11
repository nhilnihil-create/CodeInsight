#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;

    ll ans = x / 11LL * 2LL;
    x %= 11LL;

    if(x != 0) {
        if(x <= 6) ans++;
        else ans += 2LL;
    }

    cout << ans << endl;
}