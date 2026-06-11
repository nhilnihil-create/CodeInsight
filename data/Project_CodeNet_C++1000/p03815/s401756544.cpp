
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll cnt = n / 11 * 2;
    ll r = n % 11;
    if (r != 0) {
        if (r <= 6)
            ++cnt;
        else
            cnt += 2;
    }
    cout << cnt << endl;

    return 0;
}

