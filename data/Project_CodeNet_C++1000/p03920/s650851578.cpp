#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

// n * (n + 1) / 2;

ll sum(ll n);
ll bsearch(ll n);

ll array[10000005];

int main()
{
    ll n;

    cin >> n;

    for (ll i = 0; i < 10000005; i++) {
        array[i] = sum(i);
    }

    
    ll p = (ll)(lower_bound(begin(array), end(array), n) - array);

    for (ll i = 1; i <= p; i++) {
        if (i != (sum(p) - n)) {
            cout << i << endl;
        }
    }

    return 0;
}

ll sum(ll n) {
    return n * (n + 1) / 2;
}

ll bsearch(ll n)
{
    ll l, r, mid;

    l = 1;
    r = n + 1;

    while (r - l > 1) {
        mid = (r + l) / 2;
        ll tmp = sum(mid);

        if (tmp == n) {
            r = l = mid;
        } else if (tmp > n) {
            r = mid + 1;
        } else {
            l = mid + 1;
        }
    }

    return l;
}
