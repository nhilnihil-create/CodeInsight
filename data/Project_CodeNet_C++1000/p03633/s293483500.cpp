#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

ll gcd(ll a, ll b) {
    while (true) {
        if (a < b) swap(a, b);
        if (b == 0) {
            break;
        }
        a %= b;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    int N;
    cin >> N;
    ll t, ans;
    cin >> ans;
    if (N == 1) {
        cout << ans << endl;
        return 0;
    }

    cin >> t;
    ans = lcm(ans, t);
    if (N == 2) {
        cout << ans << endl;
        return 0;
    }

    FOR (i, 2, N) {
        cin >> t;
        ans = lcm(ans, t);
    }
    cout << ans << endl;

    return 0;
}