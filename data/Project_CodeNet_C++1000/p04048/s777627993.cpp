/*
  Author : lifehappy
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define endl '\n'
#define mid (l + r >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define ls rt << 1
#define rs rt << 1 | 1

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double pi = acos(-1.0);
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;

inline ll read() {
    ll f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-')    f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f * x;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n = read(), x = read();
    printf("%lld\n", 3 * (n - __gcd(n, x)));
    return 0;
}
