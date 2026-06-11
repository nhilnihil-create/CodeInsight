#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 105;
int n;
char s[N];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int res = 1e9;
    rep(c, 'a', 'z') {
        bool ff = 0;
        int ans = 1e9, lst;
        for (int j = n; j; --j) {
            if (s[j] == c) {
                if (!ff) {
                    ans = n - j, ff = 1;
                } else {
                    ans = max(ans, lst - 1 - j);
                }
                lst = j;
            }
        }
        ans = max(ans, lst - 1);
        res = min(res, ans);
    }
    printf("%d\n", res);
    return 0;
}
