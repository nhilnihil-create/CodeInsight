// 14:00
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

char s[10];
ll p10[20];

bool check(ll x) {
    cout << "? " << x << endl;
    scanf("%s", s);
    return (*s == 'Y');
}

inline ll get1(int x) {
    return p10[x - 1];
}

inline ll get9(int x) {
    return p10[x] - 1;
}

int main() {

    for (int i = p10[0] = 1; i <= 11; ++i)
        p10[i] = p10[i - 1] * 10;

    int num;
    if (check(1) == check(1e12)) {
        int l = 1, r = 11;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(get9(mid))) r = (num = mid) - 1;
            else l = mid + 1;
        }
    } else {
        int l = 1, r = 11;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(get1(mid))) l = (num = mid) + 1;
            else r = mid - 1;
        }
    }

    ll l = get1(num), r = get9(num), res;

    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(10ll * mid)) r = (res = mid) - 1;
        else l = mid + 1;
    }

    cout << "! " << res << endl;

    return 0;
}
