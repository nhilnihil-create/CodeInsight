/*
1. 只有 "-" 号后面才有 "("
2. 最多只会存在两层嵌套。假设有三层：-(A-(B-(C-D))), 显然 -(C-D) 还是 -(C-D)，可以变化成 -(A-B)-(C-D)，层数变少.

由此得出 DP 解法：f[i, j] 表示结束第 i 个数时，有 j 个左括号尚未匹配的答案，j = 0/1/2
*/
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, x, f[3];

int read() {
    int x = 0, op = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') op = -1;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
    return x * op;
}

int main() {
    cin >> n;
    f[1] = f[2] = -1e18;
    rep(i, 1, n) {
        x = read();
        f[0] += x, f[1] -= x, f[2] += x;
        if (x < 0)
            f[2] = max(f[2], f[1]), f[1] = max(f[1], f[0]);  // 在 x 前加一个 '('
        f[0] = max(f[0], f[1]), f[1] = max(f[1], f[2]);  // 在 x 后加一个 ')'
    }
    printf("%lld\n", f[0]);
    return 0;
}
