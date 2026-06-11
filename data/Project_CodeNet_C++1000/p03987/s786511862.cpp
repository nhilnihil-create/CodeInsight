
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e5;
int n, a[nsz + 5], l[nsz + 5], r[nsz + 5];
num ans;
int sz, s[nsz + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> a[i];
    }
    cont (i, n) {
        int cur = a[i];
        for (; sz && a[s[sz]] >= cur; --sz);
        l[i] = s[sz] + 1;
        s[++sz] = i;
    }
    for (; sz; l[s[sz]] = s[sz - 1] + 1, --sz);
    s[0] = n + 1;
    sz = 0;
    for (int i = n; i >= 1; --i) {
        int cur = a[i];
        for (; sz && a[s[sz]] >= cur; --sz);
        r[i] = s[sz] - 1;
        s[++sz] = i;
    }
    for (; sz; r[s[sz]] = s[sz - 1] - 1, --sz);
    cont (i, n) {
        ans += (num) (i - l[i] + 1) * (r[i] - i + 1) * a[i];
    }
    cout << ans << ln;
}