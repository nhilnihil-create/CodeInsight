// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fir first
#define sec second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

inline int read() {
    int res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}

int n, m, r[N * 2];
ll ans, buc[26];
char s[N * 2], t[N];

inline void manacher() {
    // create s
    s[n] = '!';
    for (int i = 1; i <= m; i++) {
        s[++n] = '#';
        s[++n] = t[i];
    }
    s[++n] = '#';
    s[n + 1] = '?';

    // main procedure of manacher
    int p = 0, mx = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        if (mx > i) x = std::min(r[p * 2 - i], mx - i);
        else x = 1;
        while (s[i + x] == s[i - x]) x++;
        if (i + x > mx) mx = i + x, p = i;
        r[i] = x;
    }
}

int main() {
    scanf("%s", t + 1);
    m = strlen(t + 1);
    // manacher();
    ans = (ll)m * (m - 1) / 2 + 1;
    for (int i = 1; i <= m; i++) buc[t[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        ans -= (ll)buc[i] * (buc[i] - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}