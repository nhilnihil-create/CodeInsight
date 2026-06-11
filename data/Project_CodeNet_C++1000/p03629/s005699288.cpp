#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 2e5 + 5;
int n, a[N], f[N], last[N], ans[N], nxt[N];
char s[N];

int main() {
    while (~scanf("%s", s)) {
        int len = strlen(s);
        for (int i = 0; i < 26; ++i) last[i] = len;
        for (int i = 0; i <= len; ++i) f[i] = (1 << 30);
        f[len + 1] = 0;
        for (int i = len - 1; ~i; --i) {
            last[s[i] - 'a'] = i;
            for (int j = 0; j < 26; ++j)
                if (f[last[j] + 1] + 1 < f[i]) {
                    // printf("%d %d\n", i, j);
                    f[i] = f[last[j] + 1] + 1;
                    ans[i] = j, nxt[i] = last[j] + 1;
                }
        }
        for (int i = 0; i < len; i = nxt[i]) putchar(ans[i] + 'a');
        putchar('\n');
    }
    return 0;
}