#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll h, w;
ll p[100005];
ll q[100005];

int main() {
    cin >> w >> h;

    for (int i = 0; i < w; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < h; i++) {
        cin >> q[i];
    }

    sort(p, p + w);
    sort(q, q + h);
    p[w] = 1ll << 60ll;
    q[h] = 1ll << 60ll;

    ll ans = 0;
    ll k, j;
    k = j = 0;
    for (ll i = 0; i < (h + 1) * (w + 1) - 1;) {
        if (p[k] < q[j]) {
            ans += p[k] * (h + 1 - j);
            k++;
            i += h + 1 - j;
        }
        else {
            ans += q[j] * (w + 1 - k);
            j++;
            i += w + 1 - k;
        }
    }

    cout << ans << endl;

    return 0;
}
