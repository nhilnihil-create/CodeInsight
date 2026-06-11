#include <bits/stdc++.h>
using namespace std;
#define N 101
int num[N], n, maxn, minn = N;
int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        num[x]++;
        maxn = max(maxn, x);
        minn = min(minn, x);
    }
    int mid = (maxn + 1) >> 1;
    bool flag = (minn >= mid) && (num[mid] == (maxn & 1) + 1);
    for (int i = maxn; i > mid && flag; i--)
        if (num[i] < 2) flag = false;
    puts(flag ? "Possible" : "Impossible");
    return 0;
}